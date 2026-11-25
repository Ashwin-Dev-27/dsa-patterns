#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int guess = low + (high - low) / 2;

            if(nums[guess] == target)
            {
                return guess;
            }

            // Left half is sorted
            if(nums[low] <= nums[guess])
            {
                if(target >= nums[low] && target < nums[guess])
                {
                    high = guess - 1;
                }
                else
                {
                    low = guess + 1;
                }
            }

            // Right half is sorted
            else
            {
                if(target > nums[guess] && target <= nums[high])
                {
                    low = guess + 1;
                }
                else
                {
                    high = guess - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: LC example 1 — target in right (rotated) portion
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int got = sol.search(nums, 0);
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[4,5,6,7,0,1,2]  target=0  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: LC example 2 — target not in array
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int got = sol.search(nums, 3);
        int exp = -1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[4,5,6,7,0,1,2]  target=3  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: LC example 3 — single element, not found
    {
        vector<int> nums = {1};
        int got = sol.search(nums, 0);
        int exp = -1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1]               target=0  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: single element — found
    {
        vector<int> nums = {1};
        int got = sol.search(nums, 1);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1]               target=1  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: two elements rotated — target at right
    {
        vector<int> nums = {3,1};
        int got = sol.search(nums, 1);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[3,1]             target=1  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: target is the pivot (minimum element)
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int got = sol.search(nums, 4);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[4,5,6,7,0,1,2]  target=4  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: no rotation (fully sorted array)
    {
        vector<int> nums = {1,2,3,4,5};
        int got = sol.search(nums, 3);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,2,3,4,5]       target=3  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: target larger than all elements
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int got = sol.search(nums, 8);
        int exp = -1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[4,5,6,7,0,1,2]  target=8  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
