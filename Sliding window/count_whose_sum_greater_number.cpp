#include<iostream>
using namespace std;

int main(){

    int arr[7]={4,5,3,8,2,9,1};
    int k=3;
    int number=10;

    int wind_sum=0;

    int count=0;

    for(int i=0;i<k;i++){
        wind_sum+=arr[i];
    }

    if(wind_sum>number){
        count++;
    }
    

    for(int i=k;i<7;i++){
        wind_sum=wind_sum-arr[i-k]+arr[i];

        if(wind_sum>number){
            count+=1;

        }
    }

    cout<<"Count:"<<count;
    return 0;
}