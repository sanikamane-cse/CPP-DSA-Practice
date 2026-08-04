#include<iostream>
using namespace std;
void add(int arr[],int size){
        int sum=0;
        for(int i=0;i<size;i++){
             sum=sum+arr[i];
        }
        
        cout<<"Sum="<<sum<<endl;
    

}
int main(){
    int arr[5]={10,20,30,40,50};
    add(arr,5);
    return 0;
}