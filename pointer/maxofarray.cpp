#include<iostream>
using namespace std;
int main(){
    int arr[5]={10,20,30,70,40};
    int* ptr=arr;
    int max=0;
    for(int i=0;i<5;i++){
        if(*(ptr+i)>max){
            max=*(ptr+i);
        }
    }
    cout<<"Maximum="<<max;
    return 0;
}