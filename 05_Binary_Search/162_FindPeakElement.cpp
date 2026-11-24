#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int result = -1;

        while (low < high)
        {
            int guess = (low + high) / 2;

            if (nums[guess] < nums[guess + 1])
            {
                low = guess + 1;
            }
            else
            {
                high = guess;
                result = guess;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: LC example 1 — peak in the middle
    {
        vector<int> nums = {1,2,3,1};
        int got = sol.findPeakElement(nums);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,2,3,1]                 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: LC example 2 — multiple peaks, converges to the highest one
    {
        vector<int> nums = {1,2,1,3,5,6,4};
        int got = sol.findPeakElement(nums);
        int exp = 5;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,2,1,3,5,6,4]           expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: single element — trivially a peak
    {
        vector<int> nums = {1};
        int got = sol.findPeakElement(nums);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1]                       expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: two elements — ascending, peak at the last index
    {
        vector<int> nums = {1,2};
        int got = sol.findPeakElement(nums);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,2]                     expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: two elements — descending, peak at the first index
    {
        vector<int> nums = {2,1};
        int got = sol.findPeakElement(nums);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[2,1]                     expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: strictly decreasing negatives — peak at the first index
    {
        vector<int> nums = {-1,-2,-3,-4};
        int got = sol.findPeakElement(nums);
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[-1,-2,-3,-4]             expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: strictly increasing — peak at the last index
    {
        vector<int> nums = {1,2,3,4};
        int got = sol.findPeakElement(nums);
        int exp = 3;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,2,3,4]                 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: multiple interior peaks — algorithm lands on the right one
    {
        vector<int> nums = {1,3,2,4,5,2};
        int got = sol.findPeakElement(nums);
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  nums=[1,3,2,4,5,2]             expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
