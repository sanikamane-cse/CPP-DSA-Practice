#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,1,2,3,4};
    int temp=0;
    int index=1;
   for(int i=1;i<5;i++){
    if(arr[i]!=arr[i-1]){
        int index=1;
         temp[index]=arr[i];
         index++;

    }
    cout<<i;
    
   }
   
}
