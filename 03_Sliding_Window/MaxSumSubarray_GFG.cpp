/*
 * ============================================================================
 *  Problem   : Max Sum Subarray of size K (GeeksforGeeks)
 *  Pattern   : Sliding Window
 *  File      : MaxSumSubarray_GFG.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use a sliding window of size k. First calculate the sum of the first k elements.
 *  Then slide the window to the right by adding the next element and subtracting
 *  the element that is no longer in the window. Keep track of the maximum sum.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the array
 *  Space : O(1)  – constant extra space
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
    int maxSubarraySum(vector<int>& arr, int k) {
        int a = arr.size();
        int low = 0;
        int high = k-1;
        int sum = 0;
        int result;
        
        for(int i =0;i<=high;i++)
        {
            sum = sum+arr[i];
        }
        
         result=sum; 
        
            while(high<a)
            {
                result = max(result,sum);
                low++;
                high++;
                
                if(high==a)
                   break;
                
                sum = sum-arr[low-1];
                sum = sum+arr[high];
            }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    {
        vector<int> arr = {100, 200, 300, 400};
        int k = 2;
        int result = sol.maxSubarraySum(arr, k);
        assert(result == 700);
        cout << "[PASS] Test 1 | arr=[100, 200, 300, 400], k=2  → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    {
        vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
        int k = 4;
        int result = sol.maxSubarraySum(arr, k);
        assert(result == 24);
        cout << "[PASS] Test 2 | arr=[1,4,2,10,2,3,1,0,20], k=4  → " << result << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    {
        vector<int> arr = {2, 3};
        int k = 2;
        int result = sol.maxSubarraySum(arr, k);
        assert(result == 5);
        cout << "[PASS] Test 3 | arr=[2, 3], k=2                → " << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    {
        vector<int> arr = {1, 2, 3, 4, 5};
        int k = 1;
        int result = sol.maxSubarraySum(arr, k);
        assert(result == 5);
        cout << "[PASS] Test 4 | arr=[1, 2, 3, 4, 5], k=1        → " << result << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    {
        vector<int> arr = {-1, -2, -3, -4};
        int k = 2;
        int result = sol.maxSubarraySum(arr, k);
        assert(result == -3);
        cout << "[PASS] Test 5 | arr=[-1, -2, -3, -4], k=2       → " << result << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
