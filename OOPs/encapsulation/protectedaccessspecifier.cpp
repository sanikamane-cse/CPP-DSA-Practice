#include<iostream>
using namespace std;
class Parent{
    protected:
    int money=1000;
};
    class Child:public Parent{
    public:
    void show(){
        cout<<money;
    }
    
   
};
int main(){
    Child c;
    c.show();
    return 0;

}