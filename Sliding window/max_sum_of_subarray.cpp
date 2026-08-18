#include<iostream>
using namespace std;

int main(){

int arr[8]={3,5,7,5,4,7,8,9};
int wind_sum=0;
int k=3;


for(int i=0;i<k;i++){
    wind_sum+=arr[i];
}

  int max_sum=wind_sum;

for(int i=k;i<8;i++){
    wind_sum=wind_sum-arr[i-k]+arr[i];
}
if(wind_sum>max_sum){
    max_sum=wind_sum;
}
cout<<wind_sum<<endl;
return 0;

}

