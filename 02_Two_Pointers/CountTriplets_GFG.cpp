/*
 * ============================================================================
 *  Problem   : Count Triplets with Given Sum  (GeeksForGeeks)
 *  Pattern   : Two Pointers (sort + fix one element + opposite-end search)
 *  File      : CountTriplets_GFG.cpp
 * ============================================================================
 *
 *  Problem Statement
 *  -----------------
 *  Given a sorted array arr[] of distinct integers and a target sum, count all
 *  triplets (i, j, k) such that arr[i] + arr[j] + arr[k] == sum,
 *  where i < j < k.
 *
 *  Approach
 *  --------
 *  Sort the array (already sorted per constraints, but sort() is safe to call).
 *  Fix arr[i] and use two pointers left = i+1, right = n-1.
 *
 *  Key Insight (when current_sum < target):
 *    Every element between left and right can pair with arr[right] to form a
 *    valid triplet with arr[i], because the array is sorted.
 *    That gives (right - left) valid triplets in one shot → add & move left++.
 *
 *  When current_sum == target or current_sum > target:
 *    right-- to bring the sum down.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N²)    – outer loop O(N) × inner two-pointer O(N)
 *  Space : O(log N) – sorting stack, O(1) extra otherwise
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
    int countTriplets(int sum, vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        
        sort(arr.begin(), arr.end());
        
        for(int i =0;i<n-2;i++)
        {
            int left=i+1;
            int right=n-1;
            
            while(left<right)
            {
                int current_sum= arr[i]+arr[left]+arr[right];
            
            if(current_sum<sum)
            {
                ans += (right-left);
                left++;
            }
            else
            {
               right--;
            }
        }
        
     }
     return ans;
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // arr = [5, 1, 3, 4, 7], sum = 12  →  4
    // After sort: [1, 3, 4, 5, 7]
    // Triplets: (1,4,7), (1,3,5+missed... let's count properly)
    // (1,4,7)=12 NO, we want < 12, so all triplets with sum < 12
    // GFG example: arr=[5,1,3,4,7], sum=12 → expected = 4
    {
        vector<int> arr = {5, 1, 3, 4, 7};
        int result = sol.countTriplets(12, arr);
        assert(result == 4);
        cout << "[PASS] Test 1 | arr=[5,1,3,4,7], sum=12  → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // arr = [4, 2, 1], sum = 2  →  0
    // After sort: [1, 2, 4]
    // No triplet can have sum < 2 when minimum triplet sum = 1+2+4 = 7
    {
        vector<int> arr = {4, 2, 1};
        int result = sol.countTriplets(2, arr);
        assert(result == 0);
        cout << "[PASS] Test 2 | arr=[4,2,1], sum=2        → " << result << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // arr = [1, 2, 3], sum = 7  →  1
    // After sort: [1, 2, 3]
    // Only triplet: (1,2,3)=6 < 7  → 1
    {
        vector<int> arr = {1, 2, 3};
        int result = sol.countTriplets(7, arr);
        assert(result == 1);
        cout << "[PASS] Test 3 | arr=[1,2,3], sum=7        → " << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // arr = [1, 2, 3, 4, 5], sum = 12  →  4
    // After sort: [1,2,3,4,5]
    // Triplets with sum < 12:
    //   (1,2,3)=6, (1,2,4)=7, (1,2,5)=8, (1,3,4)=8, (1,3,5)=9,
    //   (1,4,5)=10, (2,3,4)=9, (2,3,5)=10, (2,4,5)=11, (3,4,5)=12 ← NOT <
    // → 9 triplets
    {
        vector<int> arr = {1, 2, 3, 4, 5};
        int result = sol.countTriplets(12, arr);
        assert(result == 9);
        cout << "[PASS] Test 4 | arr=[1,2,3,4,5], sum=12  → " << result << endl;
    }

    cout << "\n✅  All 4 tests passed." << endl;
    return 0;
}
