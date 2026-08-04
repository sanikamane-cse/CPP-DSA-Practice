#include<iostream>
using namespace std;
int main(){
    int arr[5]={2,4,7,9,5};

    int even=0;
    int odd=0;
    
    int* ptr=arr;

    for(int i=0;i<5;i++){
        if(*(ptr+i)%2==0){
          even++;
        }else{
            odd--;
        }
    }
    cout<<"Even="<<even<<endl;
    cout<<"odd="<<odd;
    return 0;

}