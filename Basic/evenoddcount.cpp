#include<iostream>
using namespace std;
int main(){
    int arr[5]={2,5,89,56,7};
    int evencount=0;
    int oddcount=0;

    for(int i=0;i<5;i++){
        if(arr[i]%2==0){
            evencount++;
        }
        else{
            oddcount++;
        }
    }
    cout<<"Even count="<<evencount<<endl;
    cout<<"Odd count="<<oddcount<<endl;
    return 0;
}