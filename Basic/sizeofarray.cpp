#include<iostream>
using namespace std;

void display(int arr[])
{
    cout << sizeof(arr);
}

int main()
{
    int arr[5] = {10,20,30,40,50};

    display(arr);

    return 0;
}