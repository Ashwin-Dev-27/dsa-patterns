/*
 * ============================================================================
 *  Problem   : Longest Substring Without Repeating Characters (LeetCode #3)
 *  Pattern   : Sliding Window (Variable-size)
 *  File      : 3_LongestSubstringWithoutRepeatingCharacters.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use two pointers (low and high) to define a variable-size sliding window.
 *  Use an unordered_map to store the frequency of characters in the current window.
 *  Expand the window by adding the character at `high`. If the number of unique
 *  characters (map size) is less than the window length `k` (which implies duplicates
 *  exist), shrink the window from the left (low) by decrementing frequency and erasing
 *  characters when their count becomes 0, until the condition `f.size() == k` is met.
 *  At each step, update the maximum length of a valid substring.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – each character is processed at most twice (once by high, once by low)
 *  Space : O(K)  – where K is the number of unique characters in the alphabet (size of hash map)
 *
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly, minor shadowing fix) ────

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>f;
        int n = s.size();
        int low = 0;
        int high = 0;
        int result = -1;
        int k;

        for(high = 0; high<n; high++)
        {
            f[s[high]]++;
            k = high-low+1;

            while(f.size()<k)
            {
                f[s[low]]--;
                
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
                k = high -low +1;
            }
            k = high - low +1;
            result = max(k,result);
        }
        if(result==-1)
        return 0;
        return result;

    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    {
        string s = "abcabcbb";
        int result = sol.lengthOfLongestSubstring(s);
        assert(result == 3);
        cout << "[PASS] Test 1 | s=\"abcabcbb\" → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    {
        string s = "bbbbb";
        int result = sol.lengthOfLongestSubstring(s);
        assert(result == 1);
        cout << "[PASS] Test 2 | s=\"bbbbb\"    → " << result << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    {
        string s = "pwwkew";
        int result = sol.lengthOfLongestSubstring(s);
        assert(result == 3);
        cout << "[PASS] Test 3 | s=\"pwwkew\"   → " << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    {
        string s = "";
        int result = sol.lengthOfLongestSubstring(s);
        assert(result == 0);
        cout << "[PASS] Test 4 | s=\"\"         → " << result << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    {
        string s = "au";
        int result = sol.lengthOfLongestSubstring(s);
        assert(result == 2);
        cout << "[PASS] Test 5 | s=\"au\"       → " << result << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
