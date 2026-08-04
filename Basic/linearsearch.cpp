#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of element in array:";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter value of key:";
    cin>>key;

    int index =-1;

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            index=i;
            break;
        }
    }
    if(index!=-1){
        cout<<"Element found at index:"<<index;
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}