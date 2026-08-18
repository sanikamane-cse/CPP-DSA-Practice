#include<iostream>
using namespace std;

int main(){

    int arr[7]={2,5,1,8,2,9,1};
    int ws=0;
    int k=3;

    for(int i=0;i<k;i++){
        ws+=arr[i];
    }

    int max_sum=ws;

    for(int i=k;i<7;i++){
        ws=ws-arr[i-k]+arr[i];

        if(ws>max_sum){
        max_sum=ws;
    }

    }
   
    cout<<"Avarage:"<<(double)max_sum/k<<endl;
    return 0;
}