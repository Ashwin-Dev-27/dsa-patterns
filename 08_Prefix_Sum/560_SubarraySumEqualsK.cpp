/*
 * ============================================================================
 *  Problem   : Subarray Sum Equals K  (LeetCode #560)
 *  Pattern   : Prefix Sum + Hash Map (frequency counting)
 *  File      : 560_SubarraySumEqualsK.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Maintain a running prefix sum.  For each index i:
 *    sum = prefix sum up to i
 *    question = sum - k
 *
 *  If (sum - k) has been seen before as a prefix sum, then the subarray
 *  between that earlier index and i has sum exactly k.
 *  We count how many times (sum - k) appeared using a hash map f[].
 *
 *  Key initialisation: f[0] = 1  (empty prefix before the array starts)
 *  This handles subarrays that start from index 0 (sum itself equals k).
 *
 *  Transitions:
 *    sum      += nums[i]
 *    result   += f[sum - k]      // count valid subarrays ending at i
 *    f[sum]++                    // record this prefix sum for future indices
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)   – single pass through the array
 *  Space : O(N)   – hash map storing at most N distinct prefix sums
 *
 *  Evolution Note  (why not sliding window?)
 *  ------------------------------------------
 *  A sliding window works for non-negative arrays only — shrinking the window
 *  guarantees the sum decreases.  Here, nums[i] can be negative, so a
 *  window can grow or shrink in any direction.
 *
 *  The prefix-sum + hash-map approach handles negative numbers correctly
 *  because it does not rely on monotonicity — it tracks exact prefix values.
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// ─── Core Solution ───────────────────────────────────────────────────────────

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        int sum    = 0;
        int result = 0;
        f[0] = 1;                           // empty prefix

        for(int i = 0; i < (int)nums.size(); i++) {
            sum    += nums[i];
            int question  = sum - k;
            int frequency = f[question];    // how many earlier prefixes match
            result += frequency;
            f[sum]++;
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int k, int expected) {
    Solution sol;
    int result = sol.subarraySum(nums, k);

    assert(result == expected);

    cout << "[";
    if (result == expected) cout << "PASS";
    else                    cout << "FAIL";
    cout << "] Test " << test_num << " | k=" << k << " | [";

    for(int i = 0; i < min((int)nums.size(), 5); ++i) {
        cout << nums[i] << (i == min((int)nums.size(), 5)-1 ? "" : ",");
    }
    if (nums.size() > 5) cout << ",...";
    cout << "]";

    cout << " -> count = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,1,1},          2, 2);   // [1,1] at index 0-1 and 1-2
    run_test(2, {1,2,3},          3, 2);   // [3] and [1,2]
    run_test(3, {1},              1, 1);   // single element equals k
    run_test(4, {-1,-1,1},        0, 1);   // [-1,-1,1] sums to 0, also [?]
    run_test(5, {3,4,7,2,-3,1,4,2}, 7, 4); // multiple valid subarrays
    run_test(6, {1},              0, 0);   // no subarray sums to 0
    run_test(7, {0,0,0,0},        0, 10);  // C(4,2)+4 = 10 subarrays
    run_test(8, {-1,2,3,-1,2},    4, 3);   // [-1,2,3], [2,3,-1], [3,-1,2] all sum to 4

    cout << "\n✅  All tests executed.\n";
    return 0;
}
