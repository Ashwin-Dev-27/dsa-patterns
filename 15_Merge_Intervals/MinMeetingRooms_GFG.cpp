/*
 * GFG — Minimum Meeting Rooms (LC 253 equivalent)
 * Pattern  : Merge Intervals
 * Difficulty: Medium
 * Link     : https://www.geeksforgeeks.org/minimum-number-meeting-rooms-required/
 * Approach : Sort start[] and end[] independently. Two-pointer sweep line:
 *            - If next start < current end  → new meeting starts before old one ends → need a new room
 *            - Else                         → a room freed up → reuse it
 *            Track running room count and its max.
 *
 * Time  : O(N log N)  — two sorts
 * Space : O(1)        — no extra data structures (sorts are in-place)
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int rooms = 0;
        int result = 0;
        int i = 0 , j = 0;
        
        while(i<n and j<n)
        {
            if(start[i] < end[j])
            {
                rooms++;
                result = max(result,rooms);
                i++;
            }
            else
            {
              rooms--;
              j++;
            }
        }
        return result;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void check(int t,
           vector<int> start, vector<int> end,
           int expected,
           const string& label) {
    Solution sol;
    int got = sol.minMeetingRooms(start, end);
    bool pass = (got == expected);
    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t
         << " | " << label
         << " -> " << got
         << "  (expected: " << expected << ")\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. Classic — two rooms needed (meetings overlap)
    check(1, {0, 5, 15}, {30, 10, 20}, 2,
          "two overlapping + one sequential");

    // 2. No overlap at all — one room sufficient
    check(2, {1, 5, 9}, {4, 8, 12}, 1,
          "all sequential meetings -> 1 room");

    // 3. All meetings at the same time — N rooms needed
    check(3, {1, 1, 1}, {4, 4, 4}, 3,
          "all simultaneous -> 3 rooms");

    // 4. Single meeting — always 1 room
    check(4, {3}, {7}, 1,
          "single meeting -> 1 room");

    // 5. Boundary touch — start == end means NO overlap (room freed before next starts)
    check(5, {0, 5}, {5, 10}, 1,
          "start[i]==end[j] -> room freed, 1 room needed");

    // 6. Cascading overlaps — each meeting overlaps the previous
    check(6, {1, 2, 3, 4}, {5, 6, 7, 8}, 4,
          "cascading overlaps -> 4 rooms");

    // 7. All end before any later starts (sorted already)
    check(7, {1, 10, 20}, {5, 15, 25}, 1,
          "no overlaps sorted input -> 1 room");

    // 8. Real-world-style: peak at 3 simultaneous meetings
    check(8, {0, 1, 2, 3, 4}, {5, 2, 4, 6, 8}, 3,
          "peak of 3 simultaneous meetings");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
