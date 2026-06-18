/*
 * ============================================================================
 *  Problem   : Maximum Sum Circular Subarray  (LeetCode #918)
 *  Pattern   : Kadane's Algorithm (with wrap-around via complement)
 *  File      : 918_MaximumSumCircularSubarray.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  The answer is the maximum of two cases:
 *    Case 1 – No wrap:  standard Kadane's max subarray sum (max_sum)
 *    Case 2 – Wrap:     total_sum - (minimum subarray sum)
 *                       (keeping the "ends" means removing the "middle minimum")
 *
 *  Edge case: if all elements are negative, max_sum < 0 and circular_sum
 *  would be 0 (removing all elements), which is invalid — return max_sum.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass tracking both max and min Kadane simultaneously
 *  Space : O(1)  – six scalar variables
 *
 *  Evolution Note  (why not simulate wrap-around directly?)
 *  --------------------------------------------------------
 *  A naive wrap simulation doubles the array and runs a sliding window —
 *  O(N) time but O(N) extra space and more complex code.
 *  The complement trick (totalSum - minSubarray) gives the same result in
 *  O(1) space, derived purely from two simultaneous Kadane passes.
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution ───────────────────────────────────────────────────────────

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_ending = nums[0];
        int max_sum    = nums[0];
        int min_ending = nums[0];
        int min_sum    = nums[0];
        int total_sum  = nums[0];

        for(int i = 1; i < (int)nums.size(); i++) {
            total_sum += nums[i];

            max_ending = max(nums[i], max_ending + nums[i]);
            max_sum    = max(max_sum, max_ending);

            min_ending = min(nums[i], min_ending + nums[i]);
            min_sum    = min(min_sum, min_ending);
        }

        // All elements negative → wrap case invalid
        if(max_sum < 0)
            return max_sum;

        int circular_sum = total_sum - min_sum;
        return max(max_sum, circular_sum);
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxSubarraySumCircular(nums);

    assert(result == expected);

    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i = 0; i < min((int)nums.size(), 5); ++i) {
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
