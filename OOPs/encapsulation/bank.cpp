#include<iostream>
using namespace std;
class BankAccount{
    private:
    double balance;
    public:
    void deposite(double ammount){
        balance=ammount;
    }
    int getBalance(){
        return balance;
    }

};
int main(){
    BankAccount b1;
    b1.deposite(10000);
    cout<<b1.getBalance();
    return 0;
}