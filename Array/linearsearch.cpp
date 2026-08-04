#include<iostream>
using namespace std;

int linearsearch(int arr[],int sz,int target){
     for(int i=0;i<sz;i++){
        if(arr[i]==target){  //found
            return i;
        }
     }
    return -1;  //not found
}
int main(){
    int arr[]={4,2,7,8,1,3,5};
    int sz=7;
    int target=5;

    cout<<linearsearch(arr ,sz, target)<<endl; 
    return 0;
}