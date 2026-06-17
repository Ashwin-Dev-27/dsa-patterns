#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = nums[0];
        int maxSum = nums[0];

        int minEnding = nums[0];
        int minSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            maxEnding = max(nums[i], maxEnding + nums[i]);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(nums[i], minEnding + nums[i]);
            minSum = min(minSum, minEnding);
        }

        return max(abs(maxSum), abs(minSum));

    }
};

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxAbsoluteSum(nums);
    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i=0; i < min((int)nums.size(), 5); ++i) {
        cout << nums[i] << (i == min((int)nums.size(), 5)-1 ? "" : ",");
    }
    if (nums.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> max abs sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,-3,2,3,-4}, 5);
    run_test(2, {2,-5,1,-4,3,-2}, 8);
    run_test(3, {1}, 1);
    run_test(4, {-1}, 1);
    run_test(5, {0}, 0);
    run_test(6, {1,2,3}, 6);
    run_test(7, {-1,-2,-3}, 6);
    run_test(8, {3,-1,2}, 4);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
