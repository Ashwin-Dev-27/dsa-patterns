/*
 * ============================================================================
 *  Problem   : Next Greater Element I  (LeetCode #496)
 *  Pattern   : Stack — Monotonic Stack
 *  Difficulty: Easy
 *  Link      : https://leetcode.com/problems/next-greater-element-i/
 *  File      : 496_NextGreaterElement.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Process nums2 from RIGHT to LEFT using a monotonic decreasing stack:
 *  - Before pushing nums2[i], pop all elements ≤ nums2[i] (they can never be
 *    the "next greater" for anything to the left).
 *  - Whatever remains on top IS the next greater element for nums2[i].
 *  - Store (element → nextGreater) in a hash map.
 *  - For each element in nums1, look up the map in O(1).
 *
 *  Why right-to-left? Because "next greater" is to the RIGHT, so we process
 *  future elements first and keep the stack as a "candidates" pool.
 *
 *  Complexity
 *  ----------
 *  Time  : O(M + N)  – one pass each over nums2 and nums1
 *  Space : O(N)      – stack + hash map, both bounded by |nums2|
 *
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>result(n);
        stack<int>st;
        unordered_map<int, int> mp;
        result[n-1] = -1;
        st.push(nums2[n-1]);
        for(int i = n-2; i>=0; i--)
        {
            while(!st.empty() and st.top()<=nums2[i])
            st.pop();
            if(st.empty())
                result[i]=-1;
            else
                result[i]=st.top();
                st.push(nums2[i]);
        }
                for (int i = 0; i < n; i++)
            mp[nums2[i]] = result[i];

        vector<int> ans;
        for (int x : nums1)
        ans.push_back(mp[x]);
        return ans;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void run_test(int t,
              vector<int> nums1, vector<int> nums2,
              vector<int> expected,
              const string& label) {
    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    bool pass = (result == expected);

    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t << " | ";
    cout << "nums1=[";
    for (int i = 0; i < (int)nums1.size(); i++)
        cout << nums1[i] << (i+1 < (int)nums1.size() ? "," : "");
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
    run_test(1, {4,1,2}, {1,3,4,2}, {-1,3,-1},
             "standard LC example 1");

    // 2. Standard LC example 2
    run_test(2, {2,4}, {1,2,3,4}, {3,-1},
             "standard LC example 2");

    // 3. Single element, no greater
    run_test(3, {1}, {1}, {-1},
             "single element in both arrays");

    // 4. Query element at the end of nums2 — always -1
    run_test(4, {1}, {2,1}, {-1},
             "queried element is last in nums2");

    // 5. All elements descending — all NGE = -1
    run_test(5, {1,2,3}, {3,2,1}, {-1,-1,-1},
             "nums2 descending: all NGE = -1");

    // 6. All elements have a next greater
    run_test(6, {1,2}, {1,2,3}, {2,3},
             "both queried elements have NGE");

    // 7. nums1 queries first element only (nums2 has clear NGE)
    run_test(7, {5}, {5,4,3,2,6}, {6},
             "5 has NGE=6 at end of nums2");

    // 8. Longer case — each element's NGE is the next in ascending nums2
    run_test(8, {5,4,3,2,1}, {1,2,3,4,5}, {-1,5,4,3,2},
             "ascending nums2: NGE(5)=-1, NGE(4)=5, NGE(3)=4, NGE(2)=3, NGE(1)=2");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
