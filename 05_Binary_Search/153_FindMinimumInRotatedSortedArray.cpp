#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<high)
        {
            int guess = (low+high)/2;
            if(nums[guess]>nums[n-1])
            {
                low = guess+1;
            }
            else
            {
                high = guess;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: LC example 1 — rotation in the middle
    {
        vector<int> nums = {3,4,5,1,2};
        int got = sol.findMin(nums);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[3,4,5,1,2]               expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: LC example 2 — larger rotation
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int got = sol.findMin(nums);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[4,5,6,7,0,1,2]           expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: LC example 3 — not rotated
    {
        vector<int> nums = {11,13,15,17};
        int got = sol.findMin(nums);
        int exp = 11;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[11,13,15,17]             expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: single element
    {
        vector<int> nums = {7};
        int got = sol.findMin(nums);
        int exp = 7;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[7]                       expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: two elements — rotated
    {
        vector<int> nums = {5,3};
        int got = sol.findMin(nums);
        int exp = 3;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[5,3]                     expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: two elements — already sorted
    {
        vector<int> nums = {3,5};
        int got = sol.findMin(nums);
        int exp = 3;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[3,5]                     expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: rotation point past the middle
    {
        vector<int> nums = {6,7,8,9,2,3,4};
        int got = sol.findMin(nums);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[6,7,8,9,2,3,4]           expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: negative values — minimum inside the rotated half
    {
        vector<int> nums = {2,3,4,-5,-4,-3,-2};
        int got = sol.findMin(nums);
        int exp = -5;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[2,3,4,-5,-4,-3,-2]       expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
