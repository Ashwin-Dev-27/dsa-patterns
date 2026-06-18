/*
 * ============================================================================
 *  Problem   : Maximum Product Subarray  (LeetCode #152)
 *  Pattern   : Kadane's Algorithm (dual-tracking: max & min)
 *  File      : 152_MaximumProductSubarray.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Unlike sum, a product can flip sign: multiplying by a negative number turns
 *  the maximum product into the minimum and vice versa.
 *  So we track both max_ending and min_ending at every position.
 *
 *  At each index i, three candidates exist:
 *    v1 = nums[i]                  (start fresh)
 *    v2 = min_ending * nums[i]     (could flip to max if nums[i] < 0)
 *    v3 = max_ending * nums[i]     (extend current max)
 *
 *  max_ending = max(v1, v2, v3)
 *  min_ending = min(v1, v2, v3)
 *  result     = max(result, max_ending)
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass
 *  Space : O(1)  – three scalar variables
 *
 *  Evolution Note  (why track the minimum?)
 *  -----------------------------------------
 *  A plain Kadane's tracking only the max breaks here: two negatives multiply
 *  to a positive, so today's minimum can become tomorrow's maximum.
 *  Tracking min_ending costs nothing extra and handles all sign-flip cases.
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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min_ending = nums[0];
        int max_ending = nums[0];
        int result = nums[0];

        for(int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = min_ending * nums[i];
            int v3 = max_ending * nums[i];

            max_ending = max(v1, max(v2, v3));
            min_ending = min(v1, min(v2, v3));
            result = max(result, max_ending);
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxProduct(nums);

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

    cout << "-> max product = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {2, 3, -2, 4}, 6);
    run_test(2, {-2, 0, -1}, 0);
    run_test(3, {-2, 3, -4}, 24);
    run_test(4, {0, 2}, 2);
    run_test(5, {-2}, -2);
    run_test(6, {-2, -3, 7}, 42);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
