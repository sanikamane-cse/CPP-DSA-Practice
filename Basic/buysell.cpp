#include<iostream>
using namespace std;
int main(){
    int arr[7]={9,2,1,9,0,6,7};

    int minPrice=arr[0];
    int maxProfit=0;

    for(int i=0;i<7;i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        int profit=arr[i]-minPrice;
        if(profit>maxProfit){
            maxProfit=profit;
        }
    }
    cout<<"Maxprofit="<<maxProfit<<endl;
    return 0;
}