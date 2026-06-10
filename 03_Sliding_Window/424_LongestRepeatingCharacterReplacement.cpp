/*
 * ============================================================================
 *  Problem   : Longest Repeating Character Replacement (LeetCode #424)
 *  Pattern   : Sliding Window
 *  File      : 424_LongestRepeatingCharacterReplacement.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use two pointers (low and high) to define a variable-size sliding window.
 *  Keep a frequency array for the characters in the current window.
 *  The condition for a valid window is `window_length - max_count <= k`, where
 *  `max_count` is the frequency of the most common character in the window.
 *  If the condition is violated, we shrink the window from the left by 
 *  incrementing `low` and updating the frequency array until the window is valid.
 *
 *  Optimization Note
 *  -----------------
 *  The user's original code calculates `max_count` by scanning the frequency
 *  array (size 256) inside the loop. This results in O(256 * N) time complexity.
 *  It can be optimized to strictly O(N) by keeping track of the historical 
 *  maximum frequency (`max_count = max(max_count, f[s[high]])`). When shrinking, 
 *  we don't even need to update `max_count` because a smaller `max_count` 
 *  wouldn't yield a longer overall result anyway!
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  (Original: O(256 * N))
 *  Space : O(1)  - frequency array size is constant (256 or 26).
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution (Original logic preserved) ────────────────────────────────

class Solution {
public:
    int findMax(vector<int> &a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++) {
            maxc = max(maxc, a[i]);
        }
        return maxc;
    }
    
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256, 0);
        int low = 0;
        int high = 0;
        int result = -1;
        
        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int length = high - low + 1;
            int max_count = findMax(f);
            int difference = length - max_count;

            while (difference > k) {
                f[s[low]]--;
                low++;
                max_count = findMax(f);
                length = high - low + 1;
                difference = length - max_count;
            }
            length = high - low + 1;
            result = max(result, length);
        }
        // return result == -1 ? 0 : result;
        // Since s consists of only uppercase English letters, n >= 1
        return result == -1 ? 0 : result;
    } 
};

// ─── Optimized Solution (O(N) time) ──────────────────────────────────────────

class OptimizedSolution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256, 0);
        int low = 0;
        int high = 0;
        int result = 0;
        int max_count = 0;
        
        for (high = 0; high < n; high++) {
            f[s[high]]++;
            max_count = max(max_count, f[s[high]]);
            
            // If the remaining characters to replace exceed k, shrink window
            int length = high - low + 1;
            if (length - max_count > k) {
                f[s[low]]--;
                low++;
                // Notice we do NOT need to update max_count here, because we
                // only care about finding a window larger than the historical max.
            }
            
            result = max(result, high - low + 1);
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    OptimizedSolution optSol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    {
        string s = "ABAB";
        int k = 2;
        int result = sol.characterReplacement(s, k);
        int optResult = optSol.characterReplacement(s, k);
        assert(result == 4);
        assert(optResult == 4);
        cout << "[PASS] Test 1 | s=\"ABAB\", k=2 → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    {
        string s = "AABABBA";
        int k = 1;
        int result = sol.characterReplacement(s, k);
        int optResult = optSol.characterReplacement(s, k);
        assert(result == 4);
        assert(optResult == 4);
        cout << "[PASS] Test 2 | s=\"AABABBA\", k=1 → " << result << endl;
    }

    cout << "\n✅  All tests passed." << endl;
    return 0;
}
