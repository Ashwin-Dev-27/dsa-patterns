/*
 * ============================================================================
 *  Problem   : Fruit Into Baskets  (LeetCode #904)
 *  Pattern   : Sliding Window (Variable-size)
 *  File      : 904_FruitIntoBaskets.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Use two pointers (low and high) to define a variable-size sliding window.
 *  Use an unordered_map to store the frequency of fruits in the window. Expand high
 *  to add fruits. If the number of distinct fruits (map size) exceeds 2, shrink
 *  the window from the left (low) until the number of distinct fruits is <= 2.
 *  At each step, calculate the window length and keep track of the maximum length.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – each element is visited at most twice
 *  Space : O(1)  – map size is at most 3 (constant space)
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ─── Core Solution (original code preserved exactly) ─────────────────────────

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>f;
        int k =2;
        int n = fruits.size();
        int low = 0;
        int high = 0;
        int result = INT_MIN;

        for(high=0; high<n; high++)
        {
            f[fruits[high]]++;

            while(f.size()>k)
            {
                f[fruits[low]]--;

                if(f[fruits[low]]==0)
                f.erase(fruits[low]);
                low++;
            }

                int length = high-low+1;
                result = max(result,length);
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

int main() {
    Solution sol;

    // ── Test 1 ──────────────────────────────────────────────────────────────
    {
        vector<int> fruits = {1, 2, 1};
        int result = sol.totalFruit(fruits);
        assert(result == 3);
        cout << "[PASS] Test 1 | fruits=[1,2,1]                     → " << result << endl;
    }

    // ── Test 2 ──────────────────────────────────────────────────────────────
    {
        vector<int> fruits = {0, 1, 2, 2};
        int result = sol.totalFruit(fruits);
        assert(result == 3);
        cout << "[PASS] Test 2 | fruits=[0,1,2,2]                   → " << result << endl;
    }

    // ── Test 3 ──────────────────────────────────────────────────────────────
    {
        vector<int> fruits = {1, 2, 3, 2, 2};
        int result = sol.totalFruit(fruits);
        assert(result == 4);
        cout << "[PASS] Test 3 | fruits=[1,2,3,2,2]                 → " << result << endl;
    }

    // ── Test 4 ──────────────────────────────────────────────────────────────
    {
        vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
        int result = sol.totalFruit(fruits);
        assert(result == 5);
        cout << "[PASS] Test 4 | fruits=[3,3,3,1,2,1,1,2,3,3,4]     → " << result << endl;
    }

    // ── Test 5 ──────────────────────────────────────────────────────────────
    {
        vector<int> fruits = {0};
        int result = sol.totalFruit(fruits);
        assert(result == 1);
        cout << "[PASS] Test 5 | fruits=[0]                         → " << result << endl;
    }

    cout << "\n✅  All 5 tests passed." << endl;
    return 0;
}
