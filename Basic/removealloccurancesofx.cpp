#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,2,4};
    int i=0;
    int x=2;
    for(int j=0;j<5;j++){
        if(arr[j]!=x){
            arr[i]=arr[j];
            i++;
        }
    }
    for(int k=0;k<i;k++){
        cout<<arr[k];

    }
    return 0;

}