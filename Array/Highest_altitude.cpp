#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int altitude = 0;
    int highest = 0;

    for(int i = 0; i < n; i++) {
        int gain;
        cin >> gain;

        altitude = altitude + gain;

        if(altitude > highest) {
            highest = altitude;
        }
    }

    cout << highest;

    return 0;
}