#include<iostream>
using namespace std;
int main(){

    int arr[7]={2,3,1,5,4,3,2};
    int k=3;
    int wind_sum=0;

    for(int i=0;i<k;i++){
       wind_sum+=arr[i];
    }

    int min_sum=wind_sum;

    for(int i=k;i<7;i++){
        wind_sum=wind_sum-arr[i-k]+arr[i];

        if(wind_sum<min_sum){
            min_sum=wind_sum;
        }

    }

    cout<<"Minimum sum:"<<min_sum;
    return 0;
}
