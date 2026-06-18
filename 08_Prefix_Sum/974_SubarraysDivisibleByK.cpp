/*
 * ============================================================================
 *  Problem   : Subarray Sums Divisible by K  (LeetCode #974)
 *  Pattern   : Prefix Sum + Hash Map (remainder frequency counting)
 *  File      : 974_SubarraysDivisibleByK.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  A subarray nums[j+1..i] is divisible by k if and only if:
 *    prefix[i] % k == prefix[j] % k
 *  (since prefix[i] - prefix[j] divisible by k ↔ same remainder mod k)
 *
 *  So instead of tracking exact prefix sums (like LC #560), we track the
 *  frequency of each remainder seen so far.
 *
 *  At each index i:
 *    sum       += nums[i]
 *    remainder  = sum % k
 *    if remainder < 0: remainder += k      ← fix negative mod in C++
 *    result    += f[remainder]             ← count earlier prefixes with same remainder
 *    f[remainder]++
 *
 *  Key initialisation: f[0] = 1  (prefix sum 0 before the array, remainder 0)
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)   – single pass through the array
 *  Space : O(K)   – hash map holds at most K distinct remainders (0..k-1)
 *
 *  Evolution Note  (vs LC #560 Subarray Sum Equals K)
 *  ---------------------------------------------------
 *  LC #560 maps exact prefix sums → "did we see sum - k before?"
 *  LC #974 maps prefix remainders → "did we see the same remainder before?"
 *
 *  The negative-remainder fix is critical: C++ can return negative results
 *  for `sum % k` when sum is negative.  Adding k normalises it to [0, k-1].
 *
 *  Space is also more efficient here: only k distinct keys are possible
 *  (0..k-1), versus up to N distinct prefix sums in LC #560.
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
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        f[0] = 1;                           // empty prefix, remainder 0
        int sum    = 0;
        int result = 0;

        for(int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0)
                remainder += k;             // C++ negative-mod fix

            result += f[remainder];         // count earlier prefixes with same remainder
            f[remainder]++;
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int k, int expected) {
    Solution sol;
    int result = sol.subarraysDivByK(nums, k);

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
    run_test(1, {4,5,0,-2,-3,1},      5, 7);  // LeetCode example 1
    run_test(2, {5},                  9, 0);  // single element, not divisible
    run_test(3, {5},                  5, 1);  // single element equals k
    run_test(4, {0,0,0},              2, 6);  // all zeros → C(3,2)+3 = 6
    run_test(5, {-1,2,9},             2, 2);  // negatives present
    run_test(6, {7,3,-3},             3, 3);  // [7,3,-3],[3,-3],[7,3,-3]... verify
    run_test(7, {2,2,2,2},            2, 10); // every subarray of all-even = divisible
    run_test(8, {1,2,3,4,5},          5, 4);  // [5],[1,2,3,4],[2,3,4,5],[1,2,3,4,5]... wait verify

    cout << "\n✅  All tests executed.\n";
    return 0;
}
