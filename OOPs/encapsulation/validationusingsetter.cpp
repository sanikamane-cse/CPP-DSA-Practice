#include<iostream>
using namespace std;
class Bank{
    private:
    double balance;
    public:
    Bank(){
        balance=0;
    }
    void deposite(double ammount){
        if(ammount>0){
            balance+=ammount;
            cout<<"Ammount deposited suuccessful"<<endl;
        }else{
            cout<<"Invalid deposite ammount"<<endl;
        }
    }
    void withdraw(double ammount){
        if(ammount<=balance){
            balance-=ammount;
            cout<<"withdraw successfully!"<<endl;
        }else{
            cout<<"Insufficient balance! "<<endl;
        }
    }
    double getBalance(){
        return balance;
    }
};
int main(){
    Bank b;
    b.deposite(5000);
    b.withdraw(2000);
    cout<<"Current Balance="<<b.getBalance()<<endl;
    return 0;
}
