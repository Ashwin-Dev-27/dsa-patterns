/*
 * ============================================================================
 *  Problem   : 3Sum Closest  (LeetCode #16)
 *  Pattern   : Two Pointers (sort + fix one element + opposite-end search)
 *  File      : 16_3SumClosest.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Sort the array. Fix one element nums[i] and use two pointers (left, right)
 *  to find a triplet sum closest to the target.
 *  Track minimum difference seen so far and update result_sum accordingly.
 *  If exact match found, return immediately.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N²)  – outer loop O(N) × inner two-pointer O(N)
 *  Space : O(1)   – no extra data structures
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly) ─────────────────────────

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result_sum =nums[0]+nums[1]+nums[2];
        int min_diff = abs(result_sum - target);

         for(int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                int diff = abs(sum - target);

        if(diff<min_diff)
        {
            min_diff = diff;
            result_sum =sum;
        }
        if(sum==target)
        {
            return target;
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
       }
     }
        return result_sum;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // [-1,2,1,-4], target=1 → closest sum = 2
    {
        vector<int> nums = {-1, 2, 1, -4};
        int res = sol.threeSumClosest(nums, 1);

        assert(res == 2);
        cout << "[PASS] Test 1 | [-1,2,1,-4] target=1  → " << res << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // [0,0,0], target=1 → closest sum = 0
    {
        vector<int> nums = {0, 0, 0};
        int res = sol.threeSumClosest(nums, 1);

        assert(res == 0);
        cout << "[PASS] Test 2 | [0,0,0] target=1       → " << res << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // [1,1,1,0], target=100 → closest sum = 3
    {
        vector<int> nums = {1, 1, 1, 0};
        int res = sol.threeSumClosest(nums, 100);

        assert(res == 3);
        cout << "[PASS] Test 3 | [1,1,1,0] target=100   → " << res << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // [1,2,5,10,11], target=12 → closest sum = 13
    {
        vector<int> nums = {1, 2, 5, 10, 11};
        int res = sol.threeSumClosest(nums, 12);

        assert(res == 13);
        cout << "[PASS] Test 4 | [1,2,5,10,11] target=12 → " << res << endl;
    }

    cout << "\n✅  All 4 tests passed." << endl;
    return 0;
}
