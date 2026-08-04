from flask import Flask, render_template, request, jsonify, redirect, url_for, flash, send_file
from flask_login import LoginManager, login_required, current_user
from apscheduler.schedulers.background import BackgroundScheduler
from datetime import datetime, timezone, timedelta
import random
import os
import atexit
import json

# Import our modules
from config import config
from models import db, init_db, User, Pole, ConsumptionLog, FaultLog, Complaint, Notification
from models import PoleStatus, ComplaintStatus, NotificationType, UserRole
from forms import ComplaintForm, AdminComplaintResponseForm, PoleForm, ReportGenerationForm
from auth import auth_bp, admin_required, user_required

# Utility functions (must be defined before create_app)
# Utility functions (must be defined before create_app)
def generate_initial_pole_data():
    """
    Smart algorithm to generate realistic initial pole data
    Based on time of day, weather patterns, and random variations
    """
    now = datetime.now(timezone.utc)
    hour = now.hour
    
    # Time-based logic for street lights
    # Night: 6 PM (18:00) to 6 AM (06:00) - Lights should be ON
    # Day: 6 AM (06:00) to 6 PM (18:00) - Lights should be OFF
    
    is_night = (hour >= 18 or hour < 6)
    
    # Probability-based light status
    if is_night:
        # 95% chance lights are ON during night
        is_on = random.random() < 0.95
    else:
        # 5% chance lights are ON during day (maintenance/testing)
        is_on = random.random() < 0.05
    
    if is_on:
        # Generate realistic current based on time
        if hour >= 18 or hour < 6:  # Night time
            # Peak hours: Higher current (brighter)
            if hour >= 19 and hour <= 23:  # Evening peak (7 PM - 11 PM)
                base_current = random.uniform(10.0, 14.0)
            elif hour >= 0 and hour <= 5:  # Late night (12 AM - 5 AM)
                base_current = random.uniform(8.0, 11.0)
            else:  # Dusk/Dawn
                base_current = random.uniform(6.0, 9.0)
        else:  # Day time (if light is on)
            base_current = random.uniform(3.0, 6.0)
        
        # Add random variation (±10%)
        current = base_current * random.uniform(0.9, 1.1)
        
        # Weather simulation (randomly reduce current for "cloudy" conditions)
        if random.random() < 0.2:  # 20% chance of reduced brightness
            current *= random.uniform(0.7, 0.9)
        
        # Round to 2 decimals
        current = round(current, 2)
        
        # Calculate power
        voltage = 230.0
        power_factor = 0.85
        power = voltage * current * power_factor
        
        # Status check (small chance of fault even when on)
        if random.random() < 0.02:  # 2% chance of fault
            status = PoleStatus.FAULT
            current = 0.0
            power = 0.0
        else:
            status = PoleStatus.OK
    else:
        # Light is OFF
        current = 0.0
        power = 0.0
        status = PoleStatus.OK
    
    return {
        'current': current,
        'power': power,
        'is_on': is_on,
        'status': status
    }

def create_initial_consumption_log(pole):
    """Create initial consumption log for new pole"""
    try:
        log = ConsumptionLog(
            pole_id=pole.id,
            timestamp=datetime.now(timezone.utc),
            current_amperes=pole.current_amperes,
            voltage=pole.voltage,
            power_watts=pole.power_watts,
            duration_hours=0.0
        )
        log.calculate_energy(0.0)
        db.session.add(log)
        db.session.commit()
        print(f"✅ Created initial log for pole {pole.pole_number}")
    except Exception as e:
        print(f"❌ Error creating initial log: {e}")

def create_pole_added_notification(pole):
    """Create notification when new pole is added"""
    try:
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.MAINTENANCE,
                title=f"New Pole Added: {pole.pole_number}",
                message=f"A new street light pole has been added at {pole.location}. "
                       f"Initial status: {'ON' if pole.is_light_on else 'OFF'}, "
                       f"Current: {pole.current_amperes}A, Power: {pole.power_watts:.0f}W",
                pole_id=pole.id
            )
            db.session.add(notification)
        db.session.commit()
        print(f"✅ Notification sent for new pole {pole.pole_number}")
    except Exception as e:
        print(f"❌ Error creating notification: {e}")

def simulate_sensor_readings():
    """Simulate current sensor readings for all poles with smart algorithm"""
    with app.app_context():
        try:
            poles = Pole.query.all()
            now = datetime.now(timezone.utc)
            hour = now.hour
            is_night = (hour >= 18 or hour < 6)
            
            for pole in poles:
                # Skip if in maintenance
                if pole.status == PoleStatus.MAINTENANCE:
                    continue
                
                # Smart fault simulation (reduced probability)
                if random.random() < app.config['FAULT_PROBABILITY']:
                    new_current = 0.0
                    create_fault_alert(pole)
                else:
                    # Realistic current based on time of day
                    if pole.is_light_on:
                        # Night time - higher current
                        if is_night:
                            if hour >= 19 and hour <= 23:
                                base_current = random.uniform(10.0, 14.0)
                            elif hour >= 0 and hour <= 5:
                                base_current = random.uniform(8.0, 11.0)
                            else:
                                base_current = random.uniform(6.0, 9.0)
                        else:
                            # Day time but light on (unusual)
                            base_current = random.uniform(3.0, 6.0)
                        
                        # Add variation
                        new_current = round(base_current * random.uniform(0.95, 1.05), 2)
                    else:
                        new_current = 0.0
                
                # Update pole current
                old_current = pole.current_amperes
                pole.update_current(new_current)
                
                # Log consumption
                log_consumption(pole)
                
                # Check for fault resolution
                if old_current == 0 and new_current > 0:
                    resolve_pole_fault(pole)
            
            db.session.commit()
            print(f"✅ Updated {len(poles)} pole readings (Hour: {hour})")
            
        except Exception as e:
            print(f"❌ Error in sensor simulation: {e}")
            db.session.rollback()

def log_consumption(pole):
    """Log energy consumption for a pole"""
    try:
        consumption_log = ConsumptionLog(
            pole_id=pole.id,
            current_amperes=pole.current_amperes,
            voltage=pole.voltage,
            power_watts=pole.power_watts
        )
        
        # Calculate energy for this interval (in hours)
        interval_hours = app.config['SENSOR_UPDATE_INTERVAL'] / 3600
        consumption_log.calculate_energy(interval_hours)
        
        db.session.add(consumption_log)
        
    except Exception as e:
        print(f"Error logging consumption for pole {pole.id}: {e}")

def create_fault_alert(pole):
    """Create fault log and notifications when pole fails"""
    try:
        # Create fault log
        fault_log = FaultLog(
            pole_id=pole.id,
            fault_type="Current Sensor Fault",
            description=f"Zero current detected on pole {pole.pole_number}",
            current_at_fault=pole.current_amperes,
            voltage_at_fault=pole.voltage
        )
        db.session.add(fault_log)
        
        # Send notifications to admins
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.FAULT,
                title=f"Pole Fault: {pole.pole_number}",
                message=f"Fault detected on pole {pole.pole_number} at {pole.location}. Current reading: 0A",
                pole_id=pole.id
            )
            db.session.add(notification)
        
        print(f"Fault alert created for pole {pole.pole_number}")
        
    except Exception as e:
        print(f"Error creating fault alert: {e}")

def resolve_pole_fault(pole):
    """Resolve pole fault when current is restored"""
    try:
        # Update fault logs
        unresolved_faults = FaultLog.query.filter_by(
            pole_id=pole.id,
            is_resolved=False
        ).all()
        
        for fault in unresolved_faults:
            fault.resolve_fault()
        
        # Send resolution notifications to admins
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.MAINTENANCE,
                title=f"Pole Restored: {pole.pole_number}",
                message=f"Pole {pole.pole_number} at {pole.location} has been restored. Current: {pole.current_amperes:.2f}A",
                pole_id=pole.id
            )
            db.session.add(notification)
        
        print(f"Fault resolved for pole {pole.pole_number}")
        
    except Exception as e:
        print(f"Error resolving fault: {e}")

def send_complaint_notification(complaint):
    """Send notification to admins about new complaint"""
    try:
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.COMPLAINT,
                title="New Complaint Received",
                message=f"New complaint from {complaint.user.full_name}: {complaint.subject}",
                complaint_id=complaint.id
            )
            db.session.add(notification)
        
        db.session.commit()
        
    except Exception as e:
        print(f"Error sending complaint notification: {e}")

def send_complaint_update_notification(complaint):
    """Send notification to user about complaint status update"""
    try:
        notification = Notification(
            user_id=complaint.user_id,
            notification_type=NotificationType.COMPLAINT,
            title="Complaint Status Updated",
            message=f"Your complaint '{complaint.subject}' status has been updated to: {complaint.status.value.title()}",
            complaint_id=complaint.id
        )
        db.session.add(notification)
        db.session.commit()
        
    except Exception as e:
        print(f"Error sending complaint update notification: {e}")

def get_consumption_chart_data():
    """Get consumption data for charts"""
    try:
        # Get data for last 24 hours
        end_time = datetime.now(timezone.utc)
        start_time = end_time - timedelta(hours=24)
        
        consumption_logs = ConsumptionLog.query.filter(
            ConsumptionLog.timestamp >= start_time
        ).order_by(ConsumptionLog.timestamp).all()
        
        # Group by hour
        hourly_data = {}
        for log in consumption_logs:
            hour_key = log.timestamp.strftime('%H:00')
            if hour_key not in hourly_data:
                hourly_data[hour_key] = {'power': 0, 'count': 0}
            hourly_data[hour_key]['power'] += log.power_watts
            hourly_data[hour_key]['count'] += 1
        
        # Calculate averages
        chart_data = {
            'labels': [],
            'power_data': []
        }
        
        for hour in sorted(hourly_data.keys()):
            avg_power = hourly_data[hour]['power'] / hourly_data[hour]['count']
            chart_data['labels'].append(hour)
            chart_data['power_data'].append(round(avg_power, 2))
        
        return chart_data
        
    except Exception as e:
        print(f"Error getting consumption chart data: {e}")
        return {'labels': [], 'power_data': []}

def cleanup_old_data():
    """Clean up old data (called by scheduler)"""
    with app.app_context():
        try:
            # Clean up old consumption logs (keep 30 days)
            cutoff_date = datetime.now(timezone.utc) - timedelta(days=30)
            old_logs = ConsumptionLog.query.filter(ConsumptionLog.timestamp < cutoff_date).all()
            
            for log in old_logs:
                db.session.delete(log)
            
            # Clean up old notifications (keep 30 days, only read ones)
            old_notifications = Notification.query.filter(
                Notification.created_at < cutoff_date,
                Notification.is_read == True
            ).all()
            
            for notification in old_notifications:
                db.session.delete(notification)
            
            db.session.commit()
            print(f"Cleaned up {len(old_logs)} old logs and {len(old_notifications)} old notifications")
            
        except Exception as e:
            print(f"Error in data cleanup: {e}")
            db.session.rollback()

def create_app(config_name='development'):
    """Application factory pattern"""
    app = Flask(__name__)
    
    # Load configuration
    app.config.from_object(config[config_name])
    
    # Initialize extensions
    db.init_app(app)
    
    # Initialize Flask-Login
    login_manager = LoginManager()
    login_manager.init_app(app)
    login_manager.login_view = 'auth.login'
    login_manager.login_message = 'Please log in to access this page.'
    login_manager.login_message_category = 'warning'
    
    @login_manager.user_loader
    def load_user(user_id):
        return User.query.get(int(user_id))
    
    # Register blueprints
    app.register_blueprint(auth_bp, url_prefix='/auth')
    
    # Initialize database (create tables if they don't exist)
    with app.app_context():
        db.create_all()
    
    # Initialize and start scheduler
    scheduler = BackgroundScheduler()
    scheduler.start()
    
    # Add sensor simulation job
    scheduler.add_job(
        func=simulate_sensor_readings,
        trigger="interval",
        seconds=app.config['SENSOR_UPDATE_INTERVAL'],
        id='sensor_simulation',
        name='Simulate Current Sensor Readings',
        replace_existing=True
    )
    
    # Add cleanup job (runs daily)
    scheduler.add_job(
        func=cleanup_old_data,
        trigger="interval",
        hours=24,
        id='data_cleanup',
        name='Clean up old data',
        replace_existing=True
    )
    
    # Shut down scheduler when exiting the app
    atexit.register(lambda: scheduler.shutdown())
    
    return app

# Create the Flask app
app = create_app()

# Main routes
@app.route('/')
def index():
    """Landing page"""
    with app.app_context():
        # Get system statistics for landing page
        stats = {
            'total_poles': Pole.query.count(),
            'active_poles': Pole.query.filter_by(status=PoleStatus.OK).count(),
            'fault_poles': Pole.query.filter_by(status=PoleStatus.FAULT).count(),
            'total_users': User.query.filter_by(role=UserRole.USER).count()
        }
    return render_template('index.html', stats=stats)

@app.route('/dashboard')
@login_required
def dashboard():
    """Redirect to appropriate dashboard based on user role"""
    if current_user.is_admin():
        return redirect(url_for('admin_dashboard'))
    else:
        return redirect(url_for('user_dashboard'))

@app.route('/user-dashboard')
@user_required
def user_dashboard():
    """User dashboard with pole status and consumption"""
    poles = Pole.query.all()
    
    # Get recent notifications for user
    notifications = Notification.query.filter_by(
        user_id=current_user.id,
        is_active=True
    ).order_by(Notification.created_at.desc()).limit(5).all()
    
    # Get user's complaint statistics
    user_complaints = {
        'total': Complaint.query.filter_by(user_id=current_user.id).count(),
        'pending': Complaint.query.filter_by(user_id=current_user.id, status=ComplaintStatus.PENDING).count(),
        'resolved': Complaint.query.filter_by(user_id=current_user.id, status=ComplaintStatus.RESOLVED).count()
    }
    
    # Get consumption data for chart (last 24 hours)
    consumption_data = get_consumption_chart_data()
    
    return render_template('user_dashboard.html', 
                         poles=poles, 
                         notifications=notifications,
                         user_complaints=user_complaints,
                         consumption_data=consumption_data)

@app.route('/admin-dashboard')
@admin_required
def admin_dashboard():
    """Admin dashboard with full system control"""
    poles = Pole.query.all()
    
    # Get system statistics
    stats = {
        'total_poles': len(poles),
        'active_poles': len([p for p in poles if p.status == PoleStatus.OK]),
        'fault_poles': len([p for p in poles if p.status == PoleStatus.FAULT]),
        'lights_on': len([p for p in poles if p.is_light_on]),
        'total_users': User.query.count(),
        'pending_complaints': Complaint.query.filter_by(status=ComplaintStatus.PENDING).count(),
        'unresolved_faults': FaultLog.query.filter_by(is_resolved=False).count()
    }
    
    # Get recent complaints
    recent_complaints = Complaint.query.order_by(Complaint.created_at.desc()).limit(5).all()
    
    # Get recent faults
    recent_faults = FaultLog.query.filter_by(is_resolved=False).order_by(FaultLog.detected_at.desc()).limit(5).all()
    
    # Get consumption data
    consumption_data = get_consumption_chart_data()
    
    return render_template('admin_dashboard.html',
                         poles=poles,
                         stats=stats,
                         recent_complaints=recent_complaints,
                         recent_faults=recent_faults,
                         consumption_data=consumption_data)

@app.route('/complaints', methods=['GET', 'POST'])
@user_required
def complaints():
    """Submit and view complaints"""
    form = ComplaintForm()
    
    if form.validate_on_submit():
        complaint = Complaint(
            user_id=current_user.id,
            pole_id=form.pole_id.data if form.pole_id.data != 0 else None,
            subject=form.subject.data,
            description=form.description.data,
            priority=form.priority.data
        )
        
        try:
            db.session.add(complaint)
            db.session.commit()
            
            flash('Complaint submitted successfully! We will review it soon.', 'success')
            
            # Notify admins about new complaint
            send_complaint_notification(complaint)
            
            return redirect(url_for('complaints'))
        except Exception as e:
            db.session.rollback()
            flash('Error submitting complaint. Please try again.', 'error')
            print(f"Complaint submission error: {e}")
    
    # Get user's complaints
    user_complaints = Complaint.query.filter_by(user_id=current_user.id).order_by(Complaint.created_at.desc()).all()
    
    return render_template('complaints.html', form=form, complaints=user_complaints)

@app.route('/admin/complaints')
@admin_required
def admin_complaints():
    """Admin view of all complaints"""
    complaints = Complaint.query.order_by(Complaint.created_at.desc()).all()
    return render_template('admin/complaints.html', complaints=complaints)

@app.route('/admin/poles/add', methods=['GET', 'POST'])
@admin_required
def add_pole():
    """Add new pole"""
    form = PoleForm()
    
    if form.validate_on_submit():
        # Generate initial realistic data based on current time
        initial_data = generate_initial_pole_data()
        
        pole = Pole(
            pole_number=form.pole_number.data.upper().strip(),
            location=form.location.data.strip(),
            latitude=form.latitude.data,
            longitude=form.longitude.data,
            voltage=form.voltage.data,
            current_amperes=initial_data['current'],
            power_watts=initial_data['power'],
            is_light_on=initial_data['is_on'],
            status=initial_data['status'],
            installation_date=form.installation_date.data
        )
        
        pole.calculate_power()
        
        try:
            db.session.add(pole)
            db.session.commit()
            
            # Create initial consumption log
            create_initial_consumption_log(pole)
            
            # Create welcome notification
            create_pole_added_notification(pole)
            
            flash(f'Pole {pole.pole_number} added successfully with real-time data!', 'success')
            return redirect(url_for('admin_dashboard'))
        except Exception as e:
            db.session.rollback()
            flash(f'Error adding pole: {str(e)}', 'error')
    
    return render_template('admin/add_pole.html', form=form)

@app.route('/admin/poles/<int:pole_id>/edit', methods=['GET', 'POST'])
@admin_required
def edit_pole(pole_id):
    """Edit existing pole"""
    pole = Pole.query.get_or_404(pole_id)
    form = PoleForm(obj=pole)
    
    if form.validate_on_submit():
        pole.pole_number = form.pole_number.data.upper().strip()
        pole.location = form.location.data.strip()
        pole.latitude = form.latitude.data
        pole.longitude = form.longitude.data
        pole.voltage = form.voltage.data
        pole.installation_date = form.installation_date.data
        
        try:
            db.session.commit()
            flash(f'Pole {pole.pole_number} updated successfully!', 'success')
            return redirect(url_for('admin_dashboard'))
        except Exception as e:
            db.session.rollback()
            flash(f'Error updating pole: {str(e)}', 'error')
    
    return render_template('admin/edit_pole.html', form=form, pole=pole)

@app.route('/admin/poles/<int:pole_id>/delete', methods=['POST'])
@admin_required
def delete_pole(pole_id):
    """Delete pole"""
    pole = Pole.query.get_or_404(pole_id)
    
    try:
        db.session.delete(pole)
        db.session.commit()
        flash(f'Pole {pole.pole_number} deleted successfully!', 'success')
    except Exception as e:
        db.session.rollback()
        flash(f'Error deleting pole: {str(e)}', 'error')
    
    return redirect(url_for('admin_dashboard'))

@app.route('/admin/complaint/<int:complaint_id>', methods=['GET', 'POST'])
@admin_required
def admin_complaint_detail(complaint_id):
    """Admin complaint response page"""
    complaint = Complaint.query.get_or_404(complaint_id)
    form = AdminComplaintResponseForm(obj=complaint)
    
    if form.validate_on_submit():
        complaint.update_status(
            ComplaintStatus(form.status.data),
            form.admin_notes.data
        )
        
        try:
            db.session.commit()
            flash('Complaint updated successfully!', 'success')
            
            # Notify user about status update
            send_complaint_update_notification(complaint)
            
        except Exception as e:
            db.session.rollback()
            flash('Error updating complaint.', 'error')
            print(f"Complaint update error: {e}")
        
        return redirect(url_for('admin_complaints'))
    
    return render_template('admin/complaint_detail.html', complaint=complaint, form=form)

@app.route('/notifications')
@user_required
def notifications():
    """User notifications page"""
    user_notifications = Notification.query.filter_by(
        user_id=current_user.id,
        is_active=True
    ).order_by(Notification.created_at.desc()).all()
    
    # Mark notifications as read
    for notification in user_notifications:
        if not notification.is_read:
            notification.mark_as_read()
    
    db.session.commit()
    
    return render_template('notifications.html', notifications=user_notifications)

@app.route('/reports')
@admin_required
def reports():
    """Admin reports page"""
    form = ReportGenerationForm()
    return render_template('reports.html', form=form)

# AJAX Routes for real-time updates
@app.route('/api/poles/status')
@login_required
def api_poles_status():
    """API endpoint to get current pole status"""
    poles = Pole.query.all()
    poles_data = []
    
    for pole in poles:
        poles_data.append({
            'id': pole.id,
            'pole_number': pole.pole_number,
            'location': pole.location,
            'current_amperes': round(pole.current_amperes, 2),
            'power_watts': round(pole.power_watts, 2),
            'status': pole.status.value,
            'status_color': pole.status_color,
            'is_light_on': pole.is_light_on,
            'last_updated': pole.last_updated.isoformat()
        })
    
    return jsonify({'poles': poles_data})

@app.route('/api/poles/<int:pole_id>/toggle', methods=['POST'])
@admin_required
def api_toggle_pole_light(pole_id):
    """API endpoint to toggle pole light"""
    pole = Pole.query.get_or_404(pole_id)
    
    try:
        new_status = pole.toggle_light()
        db.session.commit()
        
        return jsonify({
            'success': True,
            'is_light_on': new_status,
            'power_watts': round(pole.power_watts, 2)
        })
    except Exception as e:
        db.session.rollback()
        return jsonify({'success': False, 'error': str(e)}), 500

@app.route('/api/notifications/count')
@login_required
def api_notification_count():
    """API endpoint to get unread notification count"""
    count = Notification.query.filter_by(
        user_id=current_user.id,
        is_read=False,
        is_active=True
    ).count()
    
    return jsonify({'count': count})

@app.route('/api/consumption/chart')
@login_required
def api_consumption_chart():
    """API endpoint for consumption chart data"""
    data = get_consumption_chart_data()
    return jsonify(data)

# Error handlers
    """Simulate current sensor readings for all poles"""
    with app.app_context():
        try:
            poles = Pole.query.all()
            
            for pole in poles:
                # Skip if in maintenance
                if pole.status == PoleStatus.MAINTENANCE:
                    continue
                
                # Simulate fault (5% chance)
                if random.random() < app.config['FAULT_PROBABILITY']:
                    new_current = 0.0
                    create_fault_alert(pole)
                else:
                    # Normal reading
                    if pole.is_light_on:
                        new_current = random.uniform(
                            app.config['MIN_CURRENT'],
                            app.config['MAX_CURRENT']
                        )
                    else:
                        new_current = 0.0
                
                # Update pole current
                old_current = pole.current_amperes
                pole.update_current(new_current)
                
                # Log consumption
                log_consumption(pole)
                
                # Check for fault resolution
                if old_current == 0 and new_current > 0:
                    resolve_pole_fault(pole)
            
            db.session.commit()
            print(f"Updated {len(poles)} pole readings")
            
        except Exception as e:
            print(f"Error in sensor simulation: {e}")
            db.session.rollback()

def log_consumption(pole):
    """Log energy consumption for a pole"""
    try:
        consumption_log = ConsumptionLog(
            pole_id=pole.id,
            current_amperes=pole.current_amperes,
            voltage=pole.voltage,
            power_watts=pole.power_watts
        )
        
        # Calculate energy for this interval (in hours)
        interval_hours = app.config['SENSOR_UPDATE_INTERVAL'] / 3600
        consumption_log.calculate_energy(interval_hours)
        
        db.session.add(consumption_log)
        
    except Exception as e:
        print(f"Error logging consumption for pole {pole.id}: {e}")

def create_fault_alert(pole):
    """Create fault log and notifications when pole fails"""
    try:
        # Create fault log
        fault_log = FaultLog(
            pole_id=pole.id,
            fault_type="Current Sensor Fault",
            description=f"Zero current detected on pole {pole.pole_number}",
            current_at_fault=pole.current_amperes,
            voltage_at_fault=pole.voltage
        )
        db.session.add(fault_log)
        
        # Send notifications to admins
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.FAULT,
                title=f"Pole Fault: {pole.pole_number}",
                message=f"Fault detected on pole {pole.pole_number} at {pole.location}. Current reading: 0A",
                pole_id=pole.id
            )
            db.session.add(notification)
        
        print(f"Fault alert created for pole {pole.pole_number}")
        
    except Exception as e:
        print(f"Error creating fault alert: {e}")

def resolve_pole_fault(pole):
    """Resolve pole fault when current is restored"""
    try:
        # Update fault logs
        unresolved_faults = FaultLog.query.filter_by(
            pole_id=pole.id,
            is_resolved=False
        ).all()
        
        for fault in unresolved_faults:
            fault.resolve_fault()
        
        # Send resolution notifications to admins
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.MAINTENANCE,
                title=f"Pole Restored: {pole.pole_number}",
                message=f"Pole {pole.pole_number} at {pole.location} has been restored. Current: {pole.current_amperes:.2f}A",
                pole_id=pole.id
            )
            db.session.add(notification)
        
        print(f"Fault resolved for pole {pole.pole_number}")
        
    except Exception as e:
        print(f"Error resolving fault: {e}")

def send_complaint_notification(complaint):
    """Send notification to admins about new complaint"""
    try:
        admin_users = User.query.filter_by(role=UserRole.ADMIN, is_active=True).all()
        for admin in admin_users:
            notification = Notification(
                user_id=admin.id,
                notification_type=NotificationType.COMPLAINT,
                title="New Complaint Received",
                message=f"New complaint from {complaint.user.full_name}: {complaint.subject}",
                complaint_id=complaint.id
            )
            db.session.add(notification)
        
        db.session.commit()
        
    except Exception as e:
        print(f"Error sending complaint notification: {e}")

def send_complaint_update_notification(complaint):
    """Send notification to user about complaint status update"""
    try:
        notification = Notification(
            user_id=complaint.user_id,
            notification_type=NotificationType.COMPLAINT,
            title="Complaint Status Updated",
            message=f"Your complaint '{complaint.subject}' status has been updated to: {complaint.status.value.title()}",
            complaint_id=complaint.id
        )
        db.session.add(notification)
        db.session.commit()
        
    except Exception as e:
        print(f"Error sending complaint update notification: {e}")

def get_consumption_chart_data():
    """Get consumption data for charts"""
    try:
        # Get data for last 24 hours
        end_time = datetime.now(timezone.utc)
        start_time = end_time - timedelta(hours=24)
        
        consumption_logs = ConsumptionLog.query.filter(
            ConsumptionLog.timestamp >= start_time
        ).order_by(ConsumptionLog.timestamp).all()
        
        # Group by hour
        hourly_data = {}
        for log in consumption_logs:
            hour_key = log.timestamp.strftime('%H:00')
            if hour_key not in hourly_data:
                hourly_data[hour_key] = {'power': 0, 'count': 0}
            hourly_data[hour_key]['power'] += log.power_watts
            hourly_data[hour_key]['count'] += 1
        
        # Calculate averages
        chart_data = {
            'labels': [],
            'power_data': []
        }
        
        for hour in sorted(hourly_data.keys()):
            avg_power = hourly_data[hour]['power'] / hourly_data[hour]['count']
            chart_data['labels'].append(hour)
            chart_data['power_data'].append(round(avg_power, 2))
        
        return chart_data
        
    except Exception as e:
        print(f"Error getting consumption chart data: {e}")
        return {'labels': [], 'power_data': []}

def cleanup_old_data():
    """Clean up old data (called by scheduler)"""
    with app.app_context():
        try:
            # Clean up old consumption logs (keep 30 days)
            cutoff_date = datetime.now(timezone.utc) - timedelta(days=30)
            old_logs = ConsumptionLog.query.filter(ConsumptionLog.timestamp < cutoff_date).all()
            
            for log in old_logs:
                db.session.delete(log)
            
            # Clean up old notifications (keep 30 days, only read ones)
            old_notifications = Notification.query.filter(
                Notification.created_at < cutoff_date,
                Notification.is_read == True
            ).all()
            
            for notification in old_notifications:
                db.session.delete(notification)
            
            db.session.commit()
            print(f"Cleaned up {len(old_logs)} old logs and {len(old_notifications)} old notifications")
            
        except Exception as e:
            print(f"Error in data cleanup: {e}")
            db.session.rollback()

# Error handlers
@app.errorhandler(404)
def not_found_error(error):
    return render_template('errors/404.html'), 404

@app.errorhandler(500)
def internal_error(error):
    db.session.rollback()
    return render_template('errors/500.html'), 500

if __name__ == '__main__':
    app.run(debug=True)