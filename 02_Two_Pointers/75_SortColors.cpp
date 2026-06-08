/*
 * ============================================================================
 *  Problem   : Sort Colors (LeetCode #75)
 *  Pattern   : Two Pointers (Dutch National Flag / 3-Way Partitioning)
 *  File      : 75_SortColors.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use three pointers (low, mid, high) to divide the array into three regions:
 *  - Elements from 0 to low-1 are 0 (red)
 *  - Elements from low to mid-1 are 1 (white)
 *  - Elements from high+1 to n-1 are 2 (blue)
 *
 *  mid scans the array:
 *  - If nums[mid] == 0, swap nums[low] and nums[mid], increment low and mid.
 *  - If nums[mid] == 1, increment mid.
 *  - If nums[mid] == 2, swap nums[mid] and nums[high], decrement high.
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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else 
             {
                    swap(nums[mid],nums[high]);
                    high--;        
             }
            }
        }

};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // [2,0,2,1,1,0] → [0,0,1,1,2,2]
    {
        vector<int> nums = {2, 0, 2, 1, 1, 0};
        sol.sortColors(nums);
        assert((nums == vector<int>{0, 0, 1, 1, 2, 2}));
        cout << "[PASS] Test 1 | [2,0,2,1,1,0] → [0,0,1,1,2,2]" << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // [2,0,1] → [0,1,2]
    {
        vector<int> nums = {2, 0, 1};
        sol.sortColors(nums);
        assert((nums == vector<int>{0, 1, 2}));
        cout << "[PASS] Test 2 | [2,0,1]       → [0,1,2]" << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // Empty array → []
    {
        vector<int> nums = {};
        sol.sortColors(nums);
        assert(nums.empty());
        cout << "[PASS] Test 3 | []            → []" << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // Single element → [0]
    {
        vector<int> nums = {0};
        sol.sortColors(nums);
        assert((nums == vector<int>{0}));
        cout << "[PASS] Test 4 | [0]           → [0]" << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    // Already sorted → [0, 1, 2]
    {
        vector<int> nums = {0, 1, 2};
        sol.sortColors(nums);
        assert((nums == vector<int>{0, 1, 2}));
        cout << "[PASS] Test 5 | [0,1,2]       → [0,1,2]" << endl;
    }

    // ── Test 6 ──────────────────────────────────────────────────────────────
    // All same → [2, 2, 2]
    {
        vector<int> nums = {2, 2, 2};
        sol.sortColors(nums);
        assert((nums == vector<int>{2, 2, 2}));
        cout << "[PASS] Test 6 | [2,2,2]       → [2,2,2]" << endl;
    }

    cout << "\n✅  All 6 tests passed." << endl;
    return 0;
}
