#include<iostream>
using namespace std;

void sumAndproduct(int arr[],int n ){
    int sum=0;
    int product=1;

    for (int i =0;i<n;i++){
        sum+= arr[i];
        product*=arr[i];

    }

    cout<<"Sum="<<sum<<endl;
    cout<<"Product="<<product<<endl;
}
int main() {
    
    int arr[] = {1, 2, 3, 4, 2};
    int n = 5;

    sumAndproduct(arr, n);

    
    return 0;
}