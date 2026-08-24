#include <iostream>
using namespace std;

int main() {

    int arr[] = {15, 18, 5, 3, 6, 4};
    int n = 6;

    int maxRight = arr[n - 1];

    cout << "Leaders: ";

    cout << maxRight << " ";

    for(int right = n - 2; right >= 0; right--) {

        if(arr[right] > maxRight) {
            cout << arr[right] << " ";
            maxRight = arr[right];
        }
    }

    return 0;
}