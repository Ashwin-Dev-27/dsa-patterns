#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_ending = nums[0];
        int max_sum = nums[0];
        int min_ending = nums[0];
        int min_sum = nums[0];
        int circular_sum = nums[0];
        int total_sum = nums[0];

        for(int i =1; i<nums.size(); i++)
        {
            total_sum = total_sum + nums[i];
            max_ending = max(nums[i], max_ending+nums[i]);
            max_sum = max(max_sum,max_ending);

            min_ending = min(nums[i], min_ending+nums[i]);
            min_sum = min(min_sum,min_ending);
        }
        if(max_sum<0)
        return max_sum;

        circular_sum = total_sum- min_sum;
        return max(max_sum,circular_sum);
    }
};

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxSubarraySumCircular(nums);
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

    cout << "-> max circular sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,-2,3,-2}, 3);
    run_test(2, {5,-3,5}, 10);
    run_test(3, {-3,-2,-3}, -2);
    run_test(4, {3}, 3);
    run_test(5, {-2}, -2);
    run_test(6, {1,2,3}, 6);
    run_test(7, {-1,-2,-3}, -1);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
