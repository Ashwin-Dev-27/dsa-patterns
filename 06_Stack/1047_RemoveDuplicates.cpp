/*
 * ============================================================================
 *  Problem   : Remove All Adjacent Duplicates In String  (LeetCode #1047)
 *  Pattern   : Stack
 *  Difficulty: Easy
 *  Link      : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 *  File      : 1047_RemoveDuplicates.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use a stack to process the string character by character.
 *  - If the stack is empty, push the current character.
 *  - If the top of the stack equals the current character, they form an
 *    adjacent duplicate pair → pop (remove both).
 *  - Otherwise push the current character onto the stack.
 *
 *  After processing, drain the stack into a result string and reverse it
 *  (since stack is LIFO, characters are in reverse order).
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the string
 *  Space : O(N)  – stack holds at most N characters
 *
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i= 0; i<s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i])
            {
                st.pop();
                continue;
            }
            else
            {
              st.push(s[i]);
            }
        }
        string result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void run_test(int t, string s, string expected, const string& label) {
    Solution sol;
    string result = sol.removeDuplicates(s);
    bool pass = (result == expected);
    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t
         << " | \"" << s << "\""
         << " -> \"" << result << "\""
         << "  (expected: \"" << expected << "\")"
         << " | " << label << "\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. Standard LC example
    run_test(1, "abbaca", "ca",
             "standard LC example: ab→abb→b→bca→ca");

    // 2. Multiple removal rounds
    run_test(2, "azxxzy", "ay",
             "azxxzy → azzy → ay");

    // 3. All removed — single duplicate pair
    run_test(3, "aa", "",
             "single pair, fully removed");

    // 4. No adjacent duplicates at all
    run_test(4, "abc", "abc",
             "no duplicates, unchanged");

    // 5. Single character — nothing to remove
    run_test(5, "a", "a",
             "single char");

    // 6. All pairs — fully collapsed
    run_test(6, "aabbcc", "",
             "three pairs: aa+bb+cc → empty");

    // 7. Chain collapse: abba → aa → empty
    run_test(7, "abba", "",
             "chain collapse: ab→abba→aa→empty");

    // 8. Nested removal leaves one char
    run_test(8, "aabbbaa", "b",
             "aa removed, bb removed, b remains, aa removed → b");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
