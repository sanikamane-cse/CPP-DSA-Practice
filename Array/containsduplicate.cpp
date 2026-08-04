#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,1};
    bool found=false;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]==arr[j]){
             found=true;
             break;
        }
    }
        if(found){
            break;
        }
    }
        if(found){
            cout<<"True(duplicate found)"<<endl;
        }else{
            cout<<"false(not found)";
        }
    
    return 0;
}