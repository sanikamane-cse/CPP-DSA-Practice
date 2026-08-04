#include<iostream>
using namespace std;
void search(int arr[],int size,int key){
    
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            cout<<"Element found at index:"<<i;
        }
    }
}
int main(){
    int arr[5]={10,20,30,40,50};

    search(arr,5,40);
    
}