/*
 * ============================================================================
 *  Problem   : Minimum Window Substring  (LeetCode #76)
 *  Pattern   : Sliding Window (Variable-size)
 *  File      : 76_MinimumWindowSubstring.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use two pointers (low and high) to define a variable-size sliding window.
 *  Maintain two frequency arrays:
 *    - needed[256]  : frequency of each character required (built from t)
 *    - have[256]    : frequency of each character in the current window
 *
 *  Expand the window by moving high. Once the window is valid (sahi() returns
 *  true — meaning have[c] >= needed[c] for all c), record the window length
 *  and try to shrink from the left to find a smaller valid window.
 *
 *  Optimization Note
 *  -----------------
 *  The original sahi() helper scans all 256 characters on every shrink step,
 *  resulting in O(256 * M) time. This can be optimized to strictly O(M + N)
 *  using a `formed` counter:
 *    - Increment `formed` when have[c] reaches needed[c] for a character that
 *      is actually required (needed[c] > 0).
 *    - Decrement `formed` when have[c] drops below needed[c] while shrinking.
 *    - The window is valid when formed == required (number of distinct chars in t).
 *  This replaces the full 256-scan with O(1) per step.
 *
 *  Complexity
 *  ----------
 *  Time  : O(M + N)   (Original: O(256 * M))
 *             M = len(s), N = len(t)
 *  Space : O(1)       – frequency arrays are size 256 (constant)
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

using namespace std;

// ─── Core Solution (original logic preserved) ────────────────────────────────

class Solution {
public:
    bool sahi(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < needed[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m < n) return "";

        vector<int> have(256, 0);
        vector<int> needed(256, 0);

        for (int i = 0; i < n; i++) {
            needed[t[i]]++;
        }

        int result = INT_MAX;
        int start  = -1;
        int low    = 0;

        for (int high = 0; high < m; high++) {
            have[s[high]]++;

            while (sahi(have, needed)) {
                int length = high - low + 1;
                if (result > length) {
                    result = length;
                    start  = low;
                }
                have[s[low]]--;
                low++;
            }
        }

        if (result == INT_MAX) return "";
        return s.substr(start, result);
    }
};

// ─── Optimized Solution (O(M + N) time) ──────────────────────────────────────

class OptimizedSolution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m < n) return "";

        vector<int> have(256, 0);
        vector<int> needed(256, 0);

        // Count how many distinct characters in t actually have a requirement
        int required = 0;
        for (char c : t) {
            needed[c]++;
            if (needed[c] == 1) required++; // first time we see this char
        }

        int formed = 0; // how many required chars are currently satisfied
        int result = INT_MAX;
        int start  = -1;
        int low    = 0;

        for (int high = 0; high < m; high++) {
            char c = s[high];
            have[c]++;

            // Check if this character just became fully satisfied
            if (needed[c] > 0 && have[c] == needed[c])
                formed++;

            // Shrink window from the left while it remains valid
            while (formed == required) {
                int length = high - low + 1;
                if (result > length) {
                    result = length;
                    start  = low;
                }

                char lc = s[low];
                have[lc]--;
                low++;

                // Check if removing s[low-1] broke satisfaction for that char
                if (needed[lc] > 0 && have[lc] < needed[lc])
                    formed--;
            }
        }

        if (result == INT_MAX) return "";
        return s.substr(start, result);
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution        sol;
    OptimizedSolution optSol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    // Classic example: "ADOBECODEBANC", t="ABC" → "BANC"
    {
        string s = "ADOBECODEBANC";
        string t = "ABC";
        string result    = sol.minWindow(s, t);
        string optResult = optSol.minWindow(s, t);
        assert(result    == "BANC");
        assert(optResult == "BANC");
        cout << "[PASS] Test 1 | s=\"ADOBECODEBANC\", t=\"ABC\"  → \"" << result << "\"" << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    // s == t exactly: only one valid window
    {
        string s = "a";
        string t = "a";
        string result    = sol.minWindow(s, t);
        string optResult = optSol.minWindow(s, t);
        assert(result    == "a");
        assert(optResult == "a");
        cout << "[PASS] Test 2 | s=\"a\", t=\"a\"                 → \"" << result << "\"" << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    // t longer than s: impossible
    {
        string s = "a";
        string t = "aa";
        string result    = sol.minWindow(s, t);
        string optResult = optSol.minWindow(s, t);
        assert(result    == "");
        assert(optResult == "");
        cout << "[PASS] Test 3 | s=\"a\", t=\"aa\"                → \"\"" << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    // t characters not present in s
    {
        string s = "hello";
        string t = "xyz";
        string result    = sol.minWindow(s, t);
        string optResult = optSol.minWindow(s, t);
        assert(result    == "");
        assert(optResult == "");
        cout << "[PASS] Test 4 | s=\"hello\", t=\"xyz\"            → \"\"" << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    // Duplicate characters in t: "aa" requires two a's in window
    {
        string s = "aab";
        string t = "aa";
        string result    = sol.minWindow(s, t);
        string optResult = optSol.minWindow(s, t);
        assert(result    == "aa");
        assert(optResult == "aa");
        cout << "[PASS] Test 5 | s=\"aab\", t=\"aa\"               → \"" << result << "\"" << endl;
    }

    // ── Test 6 ──────────────────────────────────────────────────────────────
    // Window is entire string
    {
        string s = "cabwefgewcwaefgcf";
        string t = "cae";
        string result    = sol.minWindow(s, t);
        string optResult = optSol.minWindow(s, t);
        assert(result    == "cwae");
        assert(optResult == "cwae");
        cout << "[PASS] Test 6 | s=\"cabwefgewcwaefgcf\", t=\"cae\" → \"" << result << "\"" << endl;
    }

    cout << "\n✅  All 6 tests passed." << endl;
    return 0;
}
