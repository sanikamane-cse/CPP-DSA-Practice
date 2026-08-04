#include<iostream>
using namespace std;
class Number{
    public:
    int value;

    Number(int x){
        value=x;
    }
};
int main(){
    Number n1(100);

    cout<<n1.value;
    return 0;

}