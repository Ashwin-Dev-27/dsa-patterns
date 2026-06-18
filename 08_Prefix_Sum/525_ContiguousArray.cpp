/*
 * ============================================================================
 *  Problem   : Contiguous Array  (LeetCode #525)
 *  Pattern   : Prefix Sum + Hash Map (state tracking)
 *  File      : 525_ContiguousArray.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  We want to find the longest subarray with an equal number of 0s and 1s.
 *  As we iterate through the array, we keep a running count of 0s and 1s.
 *  The "state" at any point is the difference: (count_of_0s - count_of_1s).
 *
 *  If we encounter the same difference at index `i` and earlier at index `j`, 
 *  it means the subarray between `j` and `i` has an equal number of 0s and 1s 
 *  (the difference didn't change, so we must have added the same amount of 0s and 1s).
 *
 *  - If difference == 0: The subarray from the very beginning (index 0) to `i` is balanced.
 *  - We use a Hash Map to store the *first* time we see each difference.
 *  - When we see a difference again, we calculate the length: `i - map[difference]`.
 *  - We keep track of the maximum length found.
 *
 *  Alternative: Treat every 0 as -1, and every 1 as 1. Then the problem reduces
 *  to finding the longest subarray with a sum of 0 (exactly like LC #560, but for length).
 *
 *  Complexity
 *  ----------
 *  Time  : O(N)  – single pass through the array
 *  Space : O(N)  – hash map storing at most N distinct differences
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution ───────────────────────────────────────────────────────────

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> f;
        int zero = 0;
        int one = 0;
        int result = 0;
        int difference;
    
        for(int i = 0; i < (int)nums.size(); i++) {
            if(nums[i] == 0)
                zero++;
            else
                one++;

            difference = zero - one;
            
            if(difference == 0) {
                result = max(result, i + 1);
                continue;
            }
            else if(f.find(difference) == f.end()) {
                f[difference] = i;
            }
            else {
                int index = f[difference];
                int length = i - index;
                result = max(length, result);
            }
        }
        return result;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.findMaxLength(nums);

    assert(result == expected);

    cout << "[";
    if (result == expected) cout << "PASS";
    else                    cout << "FAIL";
    cout << "] Test " << test_num << " | [";

    for(int i = 0; i < min((int)nums.size(), 5); ++i) {
        cout << nums[i] << (i == min((int)nums.size(), 5)-1 ? "" : ",");
    }
    if (nums.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> max length = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {0,1}, 2);
    run_test(2, {0,1,0}, 2);
    run_test(3, {0,0,0,1,1,1}, 6);
    run_test(4, {0,0,1,0,0,0,1,1}, 6); // indices 2 to 7 -> length 6
    run_test(5, {0,0,0}, 0);
    run_test(6, {1,1,1}, 0);
    run_test(7, {0,1,1,0,1,1,1,0}, 4); // indices 0 to 3 or 1 to 4 -> length 4
    run_test(8, {1}, 0);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
