#include <iostream>
using namespace std;

class Solution {
public:

    int minStartvalue(int nums[], int n) {
        int runningSum = 0;
        int minSum = runningSum;

        for(int i = 0; i < n; i++) {
            runningSum = runningSum + nums[i];

            if(runningSum < minSum) {
                minSum = runningSum;
            }
        }

        int ans = 1 - minSum;
        return ans;
    }
};

int main() {

    int nums[] = {-3, 2, -3, 4, 2};
    int n = 5;

    Solution obj;

    int result = obj.minStartvalue(nums, n);

    cout << result;

    return 0;
}