/*
 * ============================================================================
 *  Problem   : Smallest Sum Contiguous Subarray  (GFG)
 *  Pattern   : Kadane's Algorithm (minimum variant)
 *  File      : SmallestSumSubarray_GFG.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Mirror of standard Kadane's, but track the minimum instead of maximum.
 *  best_ending = minimum subarray sum ending at the current index.
 *
 *  At each step, either:
 *    • Extend the previous subarray: best_ending + a[i]
 *    • Start fresh from a[i]
 *  Take the minimum of both options.  Track the global minimum in ans.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass
 *  Space : O(1)  – two scalar variables
 *
 *  Evolution Note  (symmetry with Kadane's max)
 *  ---------------------------------------------
 *  Replacing max() with min() throughout the standard Kadane's algorithm
 *  directly yields the minimum-sum subarray.  The same "discard a positive
 *  running sum" logic applies: a positive running total only inflates the
 *  sum, so it's better to restart from the current element.
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
    int smallestSumSubarray(vector<int>& a) {
        int n = a.size();
        int ans = a[0];
        int best_ending = a[0];

        for(int i = 1; i < n; i++) {
            int v1 = best_ending + a[i];
            int v2 = a[i];
            best_ending = min(v1, v2);
            ans = min(ans, best_ending);
        }
        return ans;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> a, int expected) {
    Solution sol;
    int result = sol.smallestSumSubarray(a);

    assert(result == expected);

    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i = 0; i < min((int)a.size(), 5); ++i) {
        cout << a[i] << (i == min((int)a.size(), 5)-1 ? "" : ",");
    }
    if (a.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> min sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {3, -4, 2, -3, -1, 7, -5}, -6);
    run_test(2, {2, 6, 8, 1, 4}, 1);
    run_test(3, {-2, -3, -4, -1}, -10);
    run_test(4, {-1, -2, -3, -4}, -10);
    run_test(5, {1}, 1);
    run_test(6, {5, 4, -1, 7, 8}, -1);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
