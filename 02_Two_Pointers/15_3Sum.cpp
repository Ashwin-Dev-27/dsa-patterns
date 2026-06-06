/*
 * ============================================================================
 *  Problem   : 3Sum  (LeetCode #15)
 *  Pattern   : Two Pointers (sort + fix one element + opposite-end search)
 *  File      : 15_3Sum.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Sort the array. Fix one element nums[i] and use two pointers (left, right)
 *  to find a pair that sums to -nums[i] (target).
 *  Skip duplicate values of i to avoid duplicate triplets.
 *  After finding a valid triplet, skip duplicate left/right values.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N²)  – outer loop O(N) × inner two-pointer O(N)
 *  Space : O(1)   – ignoring output, no extra data structures
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly) ─────────────────────────

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        int i;
        for(int i =0;i<n-2;i++)
        {
            if(i>0 and nums[i]==nums[i-1])
            continue;
           int left = i+1;
           int right = n-1;
           int target = -nums[i];
        while(left<right)
        {
            int s = nums[left]+nums[right];
            if(s==target)
            {
                result.push_back(
                    {nums[i],nums[left],nums[right]}
                );
            left++;
            right--;
    
        while(left<right and nums[left]==nums[left-1])
        left++;
        while(right<right and nums[right]==nums[right+1])
        right--;
            }
        else if(s<target)    
        {
            left++;
        }
        else
        {
            right--;
        }
        }
    }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "]";
        if (i + 1 < (int)res.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // [-1,0,1,2,-1,-4] → [[-1,-1,2],[-1,0,1]]
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        auto res = sol.threeSum(nums);
        vector<vector<int>> expected = {{-1,-1,2},{-1,0,1}};

        assert(res == expected);
        cout << "[PASS] Test 1 | [-1,0,1,2,-1,-4]  → ";
        printResult(res);
        cout << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // [0,1,1] → []  (no valid triplet)
    {
        vector<int> nums = {0, 1, 1};
        auto res = sol.threeSum(nums);
        vector<vector<int>> expected = {};

        assert(res == expected);
        cout << "[PASS] Test 2 | [0,1,1]            → []" << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // [0,0,0] → [[0,0,0]]
    {
        vector<int> nums = {0, 0, 0};
        auto res = sol.threeSum(nums);
        vector<vector<int>> expected = {{0,0,0}};

        assert(res == expected);
        cout << "[PASS] Test 3 | [0,0,0]            → [[0,0,0]]" << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // [-2,0,0,2,2] → [[-2,0,2]]
    {
        vector<int> nums = {-2, 0, 0, 2, 2};
        auto res = sol.threeSum(nums);
        vector<vector<int>> expected = {{-2,0,2}};

        assert(res == expected);
        cout << "[PASS] Test 4 | [-2,0,0,2,2]       → [[-2,0,2]]" << endl;
    }

    cout << "\n✅  All 4 tests passed." << endl;
    return 0;
}
