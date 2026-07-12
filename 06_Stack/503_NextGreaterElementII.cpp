/*
 * ============================================================================
 *  Problem   : Next Greater Element II  (LeetCode #503)
 *  Pattern   : Stack — Monotonic Stack (circular array)
 *  Difficulty: Medium
 *  Link      : https://leetcode.com/problems/next-greater-element-ii/
 *  File      : 503_NextGreaterElementII.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Circular array — each element's "next greater" can wrap around.
 *  Simulate a doubled pass using a pre-loaded stack:
 *
 *  Phase 1 (pre-load): push nums[0..n-2] onto the stack (right-to-left order
 *  is implicitly handled by processing i = n-1 downward first).
 *
 *  Actually the approach here:
 *  - Pre-load stack with nums[0..n-2] (these are the "wrap-around" candidates
 *    that come after the last element circularly).
 *  - Then iterate i = n-1 down to 0:
 *      · Pop stack while top <= nums[i]  (they are not greater)
 *      · result[i] = stack empty ? -1 : st.top()
 *      · Push nums[i] for use by earlier indices
 *
 *  Key insight: pre-loading indices 0..n-2 simulates seeing those elements
 *  again after the end of the array (circular wrap).
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – each element is pushed and popped at most twice
 *  Space : O(N)  – stack holds at most N elements
 *
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n =nums.size();
        stack<int>st;
        vector<int>result(n,-1);
        for(int i = n-2; i>=0; i--)
        {
            st.push(nums[i]);
        }
        for(int i =n-1; i>=0; i--)
        {
            while(!st.empty() and st.top()<=nums[i])
            {
                st.pop();
            }
            if(st.empty())
            result[i] = -1;
            else
            result[i]=st.top();
            st.push(nums[i]);
        }
        return result;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void run_test(int t, vector<int> nums, vector<int> expected, const string& label) {
    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);
    bool pass = (result == expected);

    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t << " | [";
    for (int i = 0; i < (int)nums.size(); i++)
        cout << nums[i] << (i+1 < (int)nums.size() ? "," : "");
    cout << "] -> [";
    for (int i = 0; i < (int)result.size(); i++)
        cout << result[i] << (i+1 < (int)result.size() ? "," : "");
    cout << "]  (expected: [";
    for (int i = 0; i < (int)expected.size(); i++)
        cout << expected[i] << (i+1 < (int)expected.size() ? "," : "");
    cout << "]) | " << label << "\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. Standard LC example 1
    // [1,2,1]: 1→2 (wraps), 2→nothing→-1, 1→2 (wraps)
    run_test(1, {1,2,1}, {2,-1,2},
             "standard LC example 1");

    // 2. Standard LC example 2
    // [1,2,3,4,3]: 1→2, 2→3, 3→4, 4→nothing→-1, 3→4(wrap)
    run_test(2, {1,2,3,4,3}, {2,3,4,-1,4},
             "standard LC example 2");

    // 3. Single element — no other element to wrap to
    run_test(3, {5}, {-1},
             "single element: no NGE possible");

    // 4. All same — equal is NOT greater, all -1
    run_test(4, {3,3,3}, {-1,-1,-1},
             "all equal: equal is not greater");

    // 5. Strictly increasing — only last element wraps and still -1
    // [1,2,3]: 1→2, 2→3, 3→wraps through 1,2 → none >3 → -1
    run_test(5, {1,2,3}, {2,3,-1},
             "strictly increasing: last has no NGE even after wrap");

    // 6. Strictly decreasing — all wrap to find a greater element
    // [3,2,1]: 3→wraps: 3 not >3 → -1; 2→wraps: 3>2 → 3; 1→wraps: 3>1 → 3
    run_test(6, {3,2,1}, {-1,3,3},
             "strictly decreasing: smaller ones wrap to front max");

    // 7. Two elements
    // [2,1]: 2→wraps: 2 not >2 → -1; 1→wraps: 2>1 → 2
    run_test(7, {2,1}, {-1,2},
             "two elements: smaller wraps to greater");

    // 8. Max at end — max itself has no NGE; all others find it
    // [5,4,3,2,1,6]: all <6 find 6; 6 wraps through 5,4,3,2,1 → none >6 → -1
    run_test(8, {5,4,3,2,1,6}, {6,6,6,6,6,-1},
             "max at end: all point to it, max itself is -1");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
