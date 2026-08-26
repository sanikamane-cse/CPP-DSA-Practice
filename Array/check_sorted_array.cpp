#include<iostream>
using namespace std;

int main(){

    int arr[]={1,2,3,4,5};
    int n=5;

    bool isSorted=true;

    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            isSorted=false;
            break;
        }
    }

    if(isSorted)
    {
        cout<<"Array is sotred";
    }

    else
    {
        cout<<"Array is not sorted";
    }
    return 0;

}