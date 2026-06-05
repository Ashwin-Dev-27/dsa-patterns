/*
 * ============================================================================
 *  Problem   : Remove Duplicates from Sorted Array  (LeetCode #26)
 *  Pattern   : Two Pointers (slow & fast pointer)
 *  File      : 26_RemoveDuplicates.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use two pointers i (slow) and j (fast).
 *  i marks the last position of a confirmed unique element.
 *  j scans forward looking for the next different element.
 *  When nums[i] != nums[j], advance i and overwrite nums[i] = nums[j].
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the array
 *  Space : O(1)  – in-place, no extra data structures
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly) ─────────────────────────

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0)
        return 0;
        int i = 0;
        int unique =1;

        for(int j=1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
                unique++;
            }
        }
        return unique;
        
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // [1,1,2] → unique = 2, nums = [1,2,_]
    {
        vector<int> nums = {1, 1, 2};
        int result = sol.removeDuplicates(nums);

        assert(result == 2);
        assert(nums[0] == 1 && nums[1] == 2);
        cout << "[PASS] Test 1 | [1,1,2]               → k=" << result
             << " | nums=[" << nums[0] << "," << nums[1] << "]" << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // [0,0,1,1,1,2,2,3,3,4] → unique = 5, nums = [0,1,2,3,4,...]
    {
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int result = sol.removeDuplicates(nums);

        assert(result == 5);
        assert(nums[0]==0 && nums[1]==1 && nums[2]==2 && nums[3]==3 && nums[4]==4);
        cout << "[PASS] Test 2 | [0,0,1,1,1,2,2,3,3,4] → k=" << result
             << " | nums=[0,1,2,3,4,...]" << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // Empty array → 0
    {
        vector<int> nums = {};
        int result = sol.removeDuplicates(nums);

        assert(result == 0);
        cout << "[PASS] Test 3 | []                    → k=" << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // All unique → k == n
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        int result = sol.removeDuplicates(nums);

        assert(result == 5);
        cout << "[PASS] Test 4 | [1,2,3,4,5]           → k=" << result << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    // All same → k == 1
    {
        vector<int> nums = {7, 7, 7, 7};
        int result = sol.removeDuplicates(nums);

        assert(result == 1);
        cout << "[PASS] Test 5 | [7,7,7,7]             → k=" << result << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
