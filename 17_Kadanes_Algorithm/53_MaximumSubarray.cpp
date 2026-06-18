/*
 * ============================================================================
 *  Problem   : Maximum Subarray  (LeetCode #53)
 *  Pattern   : Kadane's Algorithm
 *  File      : 53_MaximumSubarray.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Maintain best_ending = the maximum subarray sum ending at the current index.
 *  At each step, either:
 *    • Extend the previous subarray: best_ending + nums[i]
 *    • Start fresh from nums[i]
 *  Take the maximum of both options.  Track the global best in ans.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the array
 *  Space : O(1)  – only two scalar variables
 *
 *  Evolution Note  (why not divide & conquer or brute force?)
 *  -----------------------------------------------------------
 *  Brute force tries every subarray → O(N²).
 *  Divide & conquer achieves O(N log N) but is significantly more complex.
 *  Kadane's collapses the problem to a single linear scan by observing that
 *  a negative running sum is never worth carrying forward — discard it and
 *  restart from the current element.
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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int best_ending = nums[0];

        for(int i = 1; i < n; i++) {
            int v1 = best_ending + nums[i];
            int v2 = nums[i];
            best_ending = max(v1, v2);
            ans = max(ans, best_ending);
        }
        return ans;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxSubArray(nums);

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

    cout << "-> max sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {-2,1,-3,4,-1,2,1,-5,4}, 6);
    run_test(2, {1}, 1);
    run_test(3, {5,4,-1,7,8}, 23);
    run_test(4, {-1}, -1);
    run_test(5, {-2,-1}, -1);
    run_test(6, {-5,-4,-1,-7,-8}, -1);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
