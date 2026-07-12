/*
 * ============================================================================
 *  Problem   : Remove All Adjacent Duplicates in String II  (LeetCode #1209)
 *  Pattern   : Stack — Stack of (char, count) pairs
 *  Difficulty: Medium
 *  Link      : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 *  File      : 1209_RemoveDuplicatesII.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use a stack of pairs (char, count). For each character:
 *  - If stack is empty OR top char != current char → push (ch, 1).
 *  - Else → increment top's count.
 *      · If count reaches k → pop (the k duplicates are removed).
 *
 *  Drain the stack to rebuild the result string (reverse at end).
 *
 *  Key advantage over naive: handles chain reactions naturally — when k
 *  duplicates are popped, the character below may now match the next incoming
 *  character, triggering another removal automatically.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass, each char pushed/popped at most once
 *  Space : O(N)  – stack holds at most N pairs
 *
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i = 0; i<s.size(); i++)
        {
            char ch = s[i];
            if(st.empty())
            {
                st.push({ch,1});
                continue;
            }
            if(st.top().first!=ch)
            {
                st.push({ch,1});
                continue;
            }
            st.top().second++;
            if(st.top().second == k)
            {
                st.pop();
            }
        }
            string result = "";
            while(!st.empty())
            {
                pair<char,int>p = st.top();
                st.pop();
                while(p.second--)
               {
                  result.push_back(p.first);
                }
            }
            reverse(result.begin(), result.end());
        return result;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void run_test(int t, string s, int k, string expected, const string& label) {
    Solution sol;
    string result = sol.removeDuplicates(s, k);
    bool pass = (result == expected);

    cout << (pass ? "[PASS]" : "[FAIL]")
         << " Test " << t
         << " | s=\"" << s << "\" k=" << k
         << " -> \"" << result << "\""
         << "  (expected: \"" << expected << "\")"
         << " | " << label << "\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. No duplicates at all — string is returned unchanged
    run_test(1, "abcd", 2, "abcd",
             "no adjacent duplicates, nothing removed");

    // 2. Standard LC example 1 — chain reactions
    // deeedbbcccbdaa: eee→ ddbbcccbdaa → dd+bb→ cccbdaa → ccc→ bdaa → bdb wait
    // Stack trace: eee popped→ (d,2); bb popped→ (d,2)(c,3)popped→ (d,2)(b,3)popped→(d,3)popped→(a,2)
    // Result: "aa"
    run_test(2, "deeedbbcccbdaa", 3, "aa",
             "LC example 1: chain reactions clear almost everything");

    // 3. Standard LC example 2 — many pairs throughout
    // pbbcggttciiippppooaais: bb,gg,tt removed → c+c=cc removed; iii → i remains;
    // pppp → in pairs: 2 removed then 2 removed; oo,aa removed; i joins prev i → removed
    // Result: "ps"
    run_test(3, "pbbcggttciiippppooaais", 2, "ps",
             "LC example 2: scattered pairs, result is just ps");

    // 4. All consecutive pairs — everything removed
    // aabbcc with k=2: aa→ bb→ cc→ all gone
    run_test(4, "aabbcc", 2, "",
             "all pairs removed, empty result");

    // 5. Triples at start and end — chain gives bcc
    // aaabccddd k=3: aaa→ ; ddd→ ; cc stays (only 2) → "bcc"
    run_test(5, "aaabccddd", 3, "bcc",
             "leading triple and trailing triple removed, middle stays");

    // 6. Single character with k=2 — can never reach k, returned unchanged
    // (LC constraints: k >= 2, so k=1 is not a valid input)
    run_test(6, "a", 2, "a",
             "single char, k=2: count never reaches k, returned as-is");

    // 7. k larger than string length — nothing can be removed
    run_test(7, "abcdef", 10, "abcdef",
             "k > length, no group can reach k, unchanged");

    // 8. Interleaved removal — chain reaction leaves one char
    // aabbaab k=2: aa→ ; bb→ ; aa→ ; b remains → "b"
    run_test(8, "aabbaab", 2, "b",
             "aabbaab: aa removed, bb removed, aa removed, b remains");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
