#include<iostream>
using namespace std;
class BankAccount{
    private:
    double balance;
    public:
    void deposite(double b){
        balance=b;
    }
    int getBalance(){
        return balance;
    }
};
int main(){
    BankAccount b1;
    b1.deposite(10000);
    cout<<"Bank account balance="<<b1.getBalance()<<endl;
    return 0;
}