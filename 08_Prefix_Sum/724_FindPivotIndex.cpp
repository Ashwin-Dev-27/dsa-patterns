/*
 * ============================================================================
 *  Problem   : Find Pivot Index  (LeetCode #724)
 *  Pattern   : Prefix Sum (running left/right balance)
 *  File      : 724_FindPivotIndex.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Compute the total sum of the array in one pass.
 *  Then iterate left to right, maintaining a running leftSum.
 *  At each index i:
 *    rightSum = totalSum - nums[i] - leftSum
 *    if leftSum == rightSum → i is the pivot
 *  Then accumulate: leftSum += nums[i]
 *
 *  We never build a prefix array — just two O(1) variables.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – two linear passes
 *  Space : O(1)  – only scalar variables
 *
 *  Evolution Note  (why not a prefix array?)
 *  -----------------------------------------
 *  The naive approach builds a prefix[] array of size N+1, then for each i
 *  checks prefix[i] == totalSum - prefix[i+1].  That works in O(N) time but
 *  costs O(N) extra space.
 *
 *  By keeping only a running leftSum we achieve identical O(N) time with
 *  O(1) space — strictly better, and the code is simpler.
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ─── Core Solution ───────────────────────────────────────────────────────────

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0;
        int right;
        for(int i = 0; i < n; i++)
            sum += nums[i];

        for(int i = 0; i < n; i++) {
            right = sum - nums[i] - left;
            if(left == right)
                return i;
            left += nums[i];
        }
        return -1;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.pivotIndex(nums);

    assert(result == expected);

    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i = 0; i < min((int)nums.size(), 5); ++i) {
        cout << nums[i] << (i == min((int)nums.size(), 5)-1 ? "" : ",");
    }
    if (nums.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> pivot = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,7,3,6,5,6}, 3);
    run_test(2, {1,2,3}, -1);
    run_test(3, {2,1,-1}, 0);
    run_test(4, {0,0,0,0}, 0);
    run_test(5, {1}, 0);
    run_test(6, {}, -1);
    run_test(7, {-1,-1,-1,-1,-1}, 2);
    run_test(8, {-7,1,5,2,-4,3,0}, 3);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
