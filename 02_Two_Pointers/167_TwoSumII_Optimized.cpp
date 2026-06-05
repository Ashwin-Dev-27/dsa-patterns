/*
 * ============================================================================
 *  Problem   : Two Sum II – Input Array Is Sorted  (LeetCode #167)
 *  Pattern   : Two Pointers (opposite-end convergence)
 *  File      : 167_TwoSumII_Optimized.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Place pointer i at the left end and pointer j at the right end of the
 *  sorted array. Compute their sum each step:
 *    • sum == target  →  return {i+1, j+1}  (problem is 1-indexed)
 *    • sum  < target  →  i++  (need a larger number, shift left pointer right)
 *    • sum  > target  →  j--  (need a smaller number, shift right pointer left)
 *
 *  Because the array is sorted, each pointer move provably eliminates all
 *  pairs involving the discarded element, guaranteeing the unique solution
 *  is found in a single linear pass.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – each element visited at most once
 *  Space : O(1)  – only two index variables, no extra data structures
 *
 *  Evolution Note  (why not brute force?)
 *  ---------------------------------------
 *  A brute-force approach uses two nested loops to check every possible
 *  pair → O(N²) time.  It completely ignores the fact that the array is
 *  sorted, wasting that structure.
 *
 *  The two-pointer technique exploits sorted order: if the current sum
 *  is too large, we know every pair using j is also too large, so we
 *  discard j in one move.  This collapses O(N²) → O(N) with zero extra
 *  memory, making it strictly dominant over brute force for this problem.
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ─── Core Solution (original logic preserved) ────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum == target)
                return {i + 1, j + 1};

            if (sum < target)
                i++;
            else if (sum > target)
                j--;
        }

        return {};
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // Trace: 2+15=17>9 → j--, 2+11=13>9 → j--, 2+7=9 ✓  → {1, 2}
    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> res = sol.twoSum(nums, target);

        assert(res[0] == 1 && res[1] == 2);
        cout << "[PASS] Test 1 | [2,7,11,15] target=9      → ["
             << res[0] << ", " << res[1] << "]" << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // Trace: 2+4=6 ✓  → {1, 3}
    {
        vector<int> nums = {2, 3, 4};
        int target = 6;
        vector<int> res = sol.twoSum(nums, target);

        assert(res[0] == 1 && res[1] == 3);
        cout << "[PASS] Test 2 | [2,3,4] target=6          → ["
             << res[0] << ", " << res[1] << "]" << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // Trace: -1+2=1 ✓  → {1, 4}
    {
        vector<int> nums = {-1, 0, 1, 2};
        int target = 1;
        vector<int> res = sol.twoSum(nums, target);

        assert(res[0] == 1 && res[1] == 4);
        cout << "[PASS] Test 3 | [-1,0,1,2] target=1       → ["
             << res[0] << ", " << res[1] << "]" << endl;
    }

    cout << "\n✅  All 3 tests passed." << endl;
    return 0;
}
