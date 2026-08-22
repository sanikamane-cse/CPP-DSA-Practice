#include<iostream>
using namespace std;

int main(){
    int arr[3][3]=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int sum=0;

    for(int i=0;i<3;i++){
       sum=sum+arr[i][i];
       sum=sum+arr[i][2-i];

    }

    sum=sum-arr[1][1];

    cout<<"Diagonal Sum="<<sum;
    
    return 0;
}