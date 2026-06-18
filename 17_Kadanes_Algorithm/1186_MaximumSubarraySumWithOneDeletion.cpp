/*
 * ============================================================================
 *  Problem   : Maximum Subarray Sum with One Deletion  (LeetCode #1186)
 *  Pattern   : Kadane's Algorithm (two-state DP)
 *  File      : 1186_MaximumSubarraySumWithOneDeletion.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Maintain two states at each index:
 *    no_delete  – max subarray sum ending here with zero deletions used
 *    one_delete – max subarray sum ending here with exactly one deletion used
 *
 *  Transitions:
 *    no_delete  = max(arr[i], prev_no_delete + arr[i])
 *    one_delete = max(
 *                   prev_no_delete,            // delete arr[i] (skip it)
 *                   prev_one_delete + arr[i]   // extend after a prior deletion
 *                 )
 *
 *  The global result is max over all positions of max(no_delete, one_delete).
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass
 *  Space : O(1)  – four scalar variables
 *
 *  Evolution Note  (why two states instead of prefix/suffix arrays?)
 *  -----------------------------------------------------------------
 *  A classic approach builds prefix[] and suffix[] Kadane arrays then for
 *  each index i returns prefix[i-1] + suffix[i+1] as the "delete i" answer.
 *  That is O(N) time but O(N) space.
 *
 *  The two-state DP achieves identical results in O(1) space by carrying
 *  forward only the previous step's values — no arrays needed.
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ─── Core Solution ───────────────────────────────────────────────────────────

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int no_delete  = arr[0];
        int one_delete = INT_MIN;   // no deletion used yet
        int result = arr[0];

        for(int i = 1; i < n; i++) {
            int prev_no_delete  = no_delete;
            int prev_one_delete = one_delete;

            no_delete = max(arr[i], prev_no_delete + arr[i]);

            // extend after prior deletion, or skip current element
            int extend = (prev_one_delete == INT_MIN) ? arr[i]
                                                      : prev_one_delete + arr[i];
            one_delete = max(extend, prev_no_delete);

            result = max(result, max(one_delete, no_delete));
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> arr, int expected) {
    Solution sol;
    int result = sol.maximumSum(arr);

    assert(result == expected);

    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i = 0; i < min((int)arr.size(), 5); ++i) {
        cout << arr[i] << (i == min((int)arr.size(), 5)-1 ? "" : ",");
    }
    if (arr.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> max sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,-2,0,3}, 4);
    run_test(2, {1,-2,-2,3}, 3);
    run_test(3, {-1,-1,-1,-1}, -1);
    run_test(4, {10,-20,30}, 40);
    run_test(5, {0}, 0);
    run_test(6, {-1,2,3,-4,5}, 10);
    run_test(7, {-1,-2}, -1);
    run_test(8, {-2}, -2);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
