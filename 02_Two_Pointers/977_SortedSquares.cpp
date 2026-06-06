/*
 * ============================================================================
 *  Problem   : Squares of a Sorted Array  (LeetCode #977)
 *  Pattern   : Two Pointers (split & merge)
 *  File      : 977_SortedSquares.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Split array into negative and positive halves.
 *  Square and reverse the negative half (so it becomes sorted ascending).
 *  Merge both sorted halves into a result array.
 *  Handle edge cases: all-negative or all-positive arrays separately.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass to split + single pass to merge
 *  Space : O(N)  – extra arrays for negative, positive, and result
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
    vector<int> sortedSquares(vector<int>& nums) {
        int a = nums.size();
        vector<int>negative;
        vector<int>positive;
        for(int i=0;i<a;i++) // Arrange Postive and negative number
        {
            if(nums[i]>=0)
            positive.push_back(nums[i]);
            else
            negative.push_back(nums[i]);
        }
        if(negative.size()==0) // If No negative elemnets Present
        {
            for(int i=0;i<positive.size();i++)
            positive[i] = positive[i]*positive[i];
            return positive;
        }
        else
        if(positive.size()==0) // If No Postive elemnets Present
        {
            for(int i=0;i<negative.size();i++)
            negative[i]=negative[i]*negative[i];
            reverse(negative.begin(),negative.end()); // Reverse negative number
            return negative;
        }
        int i=0,j=0;
        int result=0;
        int n= negative.size(); // Assign negative array as n
        int p =positive.size(); // Assign positive array as p
        vector<int> res(n+p);   // Both Array combining

        for(int i=0;i<n;i++)
        negative[i] = negative[i]*negative[i];
        reverse(negative.begin(),negative.end());

        for(int i=0;i<p;i++)
        positive[i]=positive[i]*positive[i];

        while(i<n and j<p)
        {
            if(negative[i]<positive[j])
            {
                res[result] = negative[i];
                result++;
                i++;
            }
            else
            {
                res[result] = positive[j];
                result++;
                j++;
            }
        }
        while(i<n) // If More elements still present and other array elements gone
        {
            res[result]=negative[i];
            result++;
            i++;
        }
        while(j<p) // If More elements still present and other array elements gone
        {
            res[result]=positive[j];
            result++;
            j++;
        }
        return res;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // [-4,-1,0,3,10] → [0,1,9,16,100]
    {
        vector<int> nums = {-4, -1, 0, 3, 10};
        vector<int> res = sol.sortedSquares(nums);
        vector<int> expected = {0, 1, 9, 16, 100};

        assert(res == expected);
        cout << "[PASS] Test 1 | [-4,-1,0,3,10]  → [0,1,9,16,100]" << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // [-7,-3,2,3,11] → [4,9,9,49,121]
    {
        vector<int> nums = {-7, -3, 2, 3, 11};
        vector<int> res = sol.sortedSquares(nums);
        vector<int> expected = {4, 9, 9, 49, 121};

        assert(res == expected);
        cout << "[PASS] Test 2 | [-7,-3,2,3,11]  → [4,9,9,49,121]" << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // All positive: [1,2,3] → [1,4,9]
    {
        vector<int> nums = {1, 2, 3};
        vector<int> res = sol.sortedSquares(nums);
        vector<int> expected = {1, 4, 9};

        assert(res == expected);
        cout << "[PASS] Test 3 | [1,2,3]          → [1,4,9]" << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // All negative: [-3,-2,-1] → [1,4,9]
    {
        vector<int> nums = {-3, -2, -1};
        vector<int> res = sol.sortedSquares(nums);
        vector<int> expected = {1, 4, 9};

        assert(res == expected);
        cout << "[PASS] Test 4 | [-3,-2,-1]       → [1,4,9]" << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    // Single element: [0] → [0]
    {
        vector<int> nums = {0};
        vector<int> res = sol.sortedSquares(nums);
        vector<int> expected = {0};

        assert(res == expected);
        cout << "[PASS] Test 5 | [0]              → [0]" << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
