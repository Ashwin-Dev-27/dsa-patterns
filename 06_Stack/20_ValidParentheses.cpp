/*
 * ============================================================================
 *  Problem   : Valid Parentheses  (LeetCode #20)
 *  Pattern   : Stack
 *  Difficulty: Easy
 *  Link      : https://leetcode.com/problems/valid-parentheses/
 *  File      : 20_ValidParentheses.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use a stack to validate matching brackets.
 *  - If the character is an opening bracket ( '(', '[', '{' ), push it.
 *  - If it's a closing bracket:
 *      - If the stack is empty → no matching opener → return false.
 *      - If top of stack matches the closer → pop (valid pair).
 *      - Otherwise → mismatch → return false.
 *  - At the end, the stack must be empty (no unmatched openers left).
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the string
 *  Space : O(N)  – stack holds at most N/2 characters
 *
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    bool isValid(string s) {   
        stack<char>st; 
        for(int i = 0; i <s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                continue;
            }

            if (st.empty())
                return false;

            if ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']')) {
                st.pop();
                continue;
            }

            return false;
        }
        return st.empty();
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void run_test(int t, string s, bool expected, const string& label) {
    Solution sol;
    bool result = sol.isValid(s);
    bool pass = (result == expected);
    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t
         << " | \"" << s << "\""
         << " -> " << (result ? "true" : "false")
         << "  (expected: " << (expected ? "true" : "false") << ")"
         << " | " << label << "\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. Single pair — valid
    run_test(1, "()", true,
             "single pair");

    // 2. All three types, sequential — valid
    run_test(2, "()[]{}", true,
             "all three types in sequence");

    // 3. Nested — valid
    run_test(3, "([])", true,
             "nested brackets");

    // 4. Type mismatch — invalid
    run_test(4, "(]", false,
             "type mismatch: ( closed by ]");

    // 5. Crossed brackets — invalid
    run_test(5, "([)]", false,
             "crossed: ( [ ) ] order wrong");

    // 6. Deep nesting — valid
    run_test(6, "{[]}", true,
             "deep nesting: { [ ] }");

    // 7. Empty string — valid (nothing to mismatch)
    run_test(7, "", true,
             "empty string is valid");

    // 8. Unclosed openers — invalid
    run_test(8, "(((", false,
             "three unclosed parens");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
