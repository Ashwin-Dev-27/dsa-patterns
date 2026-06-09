/*
 * ============================================================================
 *  Problem   : Minimum Size Subarray Sum  (LeetCode #209)
 *  Pattern   : Sliding Window (Variable-size)
 *  File      : 209_MinSizeSubarraySum.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use two pointers (low and high) to define a variable-size sliding window.
 *  Expand the window by adding nums[high] to the sum. When the sum is >= target,
 *  shrink the window from the left (low) while updating the minimum length.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – each element is visited at most twice (once by high, once by low)
 *  Space : O(1)  – constant extra space
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly) ─────────────────────────

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int result = INT_MAX;

        while(high<n)
        {
            sum = sum +nums[high];

            while(sum>=target)
            {
                int length = high-low+1;
                result = min(result,length);
                sum = sum-nums[low];
                low++;
            }
            high++;
        }
        if(result == INT_MAX)
        return 0;
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    {
        vector<int> nums = {2, 3, 1, 2, 4, 3};
        int target = 7;
        int result = sol.minSubArrayLen(target, nums);
        assert(result == 2);
        cout << "[PASS] Test 1 | nums=[2,3,1,2,4,3], target=7 → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    {
        vector<int> nums = {1, 4, 4};
        int target = 4;
        int result = sol.minSubArrayLen(target, nums);
        assert(result == 1);
        cout << "[PASS] Test 2 | nums=[1,4,4], target=4       → " << result << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    {
        vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
        int target = 11;
        int result = sol.minSubArrayLen(target, nums);
        assert(result == 0);
        cout << "[PASS] Test 3 | nums=[1,1,1,1,1,1,1,1], target=11 → " << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    {
        vector<int> nums = {2, 3, 1, 1, 1, 1};
        int target = 5;
        int result = sol.minSubArrayLen(target, nums);
        assert(result == 2);
        cout << "[PASS] Test 4 | nums=[2,3,1,1,1,1], target=5 → " << result << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    {
        vector<int> nums = {1, 1, 1};
        int target = 3;
        int result = sol.minSubArrayLen(target, nums);
        assert(result == 3);
        cout << "[PASS] Test 5 | nums=[1,1,1], target=3       → " << result << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
