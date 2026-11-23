#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high = n-1;

        while (low<=high)
        {
            int guess = (low+high)/2;
            if(nums[guess]==target)
            return guess;
            if(nums[guess]<target)
            low = guess+1;
            else
            high = guess-1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: LC example 1 — target found in middle-right
    {
        vector<int> nums = {-1,0,3,5,9,12};
        int got = sol.search(nums, 9);
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[-1,0,3,5,9,12]  target=9   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: LC example 2 — target not in array
    {
        vector<int> nums = {-1,0,3,5,9,12};
        int got = sol.search(nums, 2);
        int exp = -1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[-1,0,3,5,9,12]  target=2   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: single element — found
    {
        vector<int> nums = {5};
        int got = sol.search(nums, 5);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[5]               target=5   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: single element — not found
    {
        vector<int> nums = {5};
        int got = sol.search(nums, 3);
        int exp = -1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[5]               target=3   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: target at index 0 (left boundary)
    {
        vector<int> nums = {1,3,5,7,9};
        int got = sol.search(nums, 1);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,3,5,7,9]       target=1   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: target at last index (right boundary)
    {
        vector<int> nums = {1,3,5,7,9};
        int got = sol.search(nums, 9);
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,3,5,7,9]       target=9   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: target exactly in middle
    {
        vector<int> nums = {1,3,5,7,9};
        int got = sol.search(nums, 5);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,3,5,7,9]       target=5   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: target smaller than all elements
    {
        vector<int> nums = {-10,-5,0,3,7};
        int got = sol.search(nums, -20);
        int exp = -1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[-10,-5,0,3,7]    target=-20 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
