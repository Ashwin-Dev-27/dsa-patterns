/*
 * ============================================================================
 *  Problem   : Longest K Unique Characters Substring (GeeksforGeeks)
 *  Pattern   : Sliding Window (Variable-size)
 *  File      : LongestKSubstr_GFG.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use a sliding window defined by low and high pointers. Use an unordered_map
 *  to store the frequency of characters in the current window. Expand high to add
 *  characters. If the map size (number of unique characters) exceeds k, shrink
 *  the window from the left (low) until the number of unique characters is <= k.
 *  When the number of unique characters is exactly k, update the maximum length.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the string
 *  Space : O(K)  – space used by the hash map of size at most K+1
 *
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly) ─────────────────────────

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> f;
    
        int result = -1;
        int low = 0;
        int high = 0;
        int n = s.size();
        
        for(high = 0;high<n;high++)
        {
            f[s[high]]++;
            
            while(f.size()>k)
            {
                f[s[low]]--;

            if(f[s[low]]==0)
            {
                f.erase(s[low]);
            }
            
            low++;
        }
        if(f.size()==k)
        {
            int length = high-low+1;
            result = max(result,length);
        }
    }
        
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    {
        string s = "aabacbebebe";
        int k = 3;
        int result = sol.longestKSubstr(s, k);
        assert(result == 7);
        cout << "[PASS] Test 1 | s=\"aabacbebebe\", k=3 → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    {
        string s = "aaaa";
        int k = 2;
        int result = sol.longestKSubstr(s, k);
        assert(result == -1);
        cout << "[PASS] Test 2 | s=\"aaaa\", k=2        → " << result << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    {
        string s = "eceba";
        int k = 2;
        int result = sol.longestKSubstr(s, k);
        assert(result == 3);
        cout << "[PASS] Test 3 | s=\"eceba\", k=2       → " << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    {
        string s = "a";
        int k = 1;
        int result = sol.longestKSubstr(s, k);
        assert(result == 1);
        cout << "[PASS] Test 4 | s=\"a\", k=1           → " << result << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    {
        string s = "abacbebebe";
        int k = 3;
        int result = sol.longestKSubstr(s, k);
        assert(result == 7);
        cout << "[PASS] Test 5 | s=\"abacbebebe\", k=3 → " << result << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
