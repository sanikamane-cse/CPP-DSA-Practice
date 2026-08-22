#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> nums = {10, 20, 30, 40, 50};
    int target = 30;

    bool found = false;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] == target) {
            cout << "Element found at index: " << i;
            found = true;
            break;
        }
    }

    if (found == false) {
        cout << "Element not found";
    }

    return 0;
}