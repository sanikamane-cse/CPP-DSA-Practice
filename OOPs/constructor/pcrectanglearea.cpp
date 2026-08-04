#include<iostream>
using namespace std;
class Rectangle{
    public:
    double length;
    double breadth;

 
    Rectangle(double l,double b){
        length=l;
        breadth=b;
    }

    
    double area(){
    return length*breadth;
    
 }
};
int main(){
 double l,b;

 cout<<"enter length=";
 cin>>l;
 cout<<"enter breadth=";
 cin>>b;

 Rectangle r1(l,b);

 cout<<r1.area();

}
