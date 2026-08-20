#include<iostream>
using namespace std;

int main(){
    
    int arr[]={12,45,32,10};
    int n=4;

    int max=arr[0];

    for(int i=1;i<n;i++){

        if(arr[i]>max){
            max=arr[i];
        }

    }
    cout<<"Maximum Element:"<<max<<endl;

    return 0;
}

