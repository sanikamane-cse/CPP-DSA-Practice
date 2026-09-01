#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    vector<int> nums = {0, 1,0,1,0,0};

    unordered_map<int, int> mp;

    int sum = 0;
    int maxLength = 0;

    mp[0] = -1;

    for (int i = 0; i < nums.size(); i++) {

     
        if (nums[i] == 0) {
            sum--;
        }
        else {
            sum++;
        }

        if (mp.find(sum) != mp.end()) {

            int length = i - mp[sum];

            if (length > maxLength) {
                maxLength = length;
            }
        }
        else {
         
            mp[sum] = i;
        }
    }

    cout << "Maximum Length: " << maxLength << endl;

    return 0;
}