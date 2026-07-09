/*
 * ============================================================================
 *  Problem   : Daily Temperatures  (LeetCode #739)
 *  Pattern   : Stack — Monotonic Stack (indices)
 *  Difficulty: Medium
 *  Link      : https://leetcode.com/problems/daily-temperatures/
 *  File      : 739_DailyTemperatures.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Process from RIGHT to LEFT, maintaining a monotonic stack of INDICES
 *  (not values). The stack always holds candidates for "next warmer day".
 *
 *  - For each day i, pop indices from the stack while the temperature at
 *    those indices is ≤ temperatures[i] (they can't be the "next warmer").
 *  - If stack is empty   → no warmer day exists → result[i] = 0.
 *  - Else                → result[i] = st.top() - i  (days to wait).
 *  - Push index i onto the stack.
 *
 *  Key difference from LC 496: we store INDICES (not values) so we can
 *  compute the distance directly.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – each index is pushed and popped at most once
 *  Space : O(N)  – stack holds at most N indices
 *
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n = temperatures.size();
        vector<int>result(n);
        result[n-1]=0;
        st.push(n-1);

        for(int i = n-2; i>=0; i--)
        {
            while(!st.empty() and temperatures[st.top()]<=temperatures[i])
            st.pop();
        
        if(st.empty())
        result[i]=0;
        else
        result[i]=st.top()-i;
        st.push(i);
        }
        return result;
    }  
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void run_test(int t, vector<int> temps, vector<int> expected, const string& label) {
    Solution sol;
    vector<int> result = sol.dailyTemperatures(temps);
    bool pass = (result == expected);

    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t << " | [";
    for (int i = 0; i < (int)temps.size(); i++)
        cout << temps[i] << (i+1 < (int)temps.size() ? "," : "");
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
    // 1. Standard LC example
    run_test(1, {73,74,75,71,69,72,76,73}, {1,1,4,2,1,1,0,0},
             "standard LC example");

    // 2. Strictly increasing — each waits exactly 1 day
    run_test(2, {30,40,50,60}, {1,1,1,0},
             "strictly increasing: all wait 1");

    // 3. Strictly decreasing — no warmer day ever
    run_test(3, {60,50,40,30}, {0,0,0,0},
             "strictly decreasing: all 0");

    // 4. All equal — equal is NOT warmer, so all 0
    run_test(4, {30,30,30,30}, {0,0,0,0},
             "all equal temps: equal is not warmer");

    // 5. Single element — no next day
    run_test(5, {50}, {0},
             "single element");

    // 6. Mixed — warmer day not always adjacent
    run_test(6, {34,80,34}, {1,0,0},
             "34 waits 1 for 80; 80 and last 34 have no warmer day");

    // 7. Peak in the middle — elements on both sides wait different amounts
    run_test(7, {50,60,50,40,70}, {1,3,2,1,0},
             "70 at end is the eventual warmer for most");

    // 8. All waiting for a final spike
    run_test(8, {100,99,98,97,96,95,200}, {6,5,4,3,2,1,0},
             "200 at end is the answer for all; wait = distance to index 6");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
