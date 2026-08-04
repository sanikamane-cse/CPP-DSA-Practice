#include<iostream>
#include<climits>
using namespace std;
int main(){

    int arr[5]={10,23,43,67,87};
    int largest=arr[0];
    int secondLargest=INT_MIN;

    for(int i=0;i<5;i++){

        if(arr[i]>largest){

            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondLargest){

            secondLargest=arr[i];
        }

    }
    cout<<"Second Largest element is:"<<secondLargest<<endl;
    return 0;
}