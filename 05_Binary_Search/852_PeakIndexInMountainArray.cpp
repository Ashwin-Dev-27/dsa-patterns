#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low < high)
        {
            int guess = (low + high) / 2;

            if (arr[guess] < arr[guess + 1])
            {
                low = guess + 1;
            }
            else
            {
                high = guess;
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
        vector<int> arr = {0,1,0};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[0,1,0]                 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: LC example 2 — peak near the start
    {
        vector<int> arr = {0,2,1,0};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[0,2,1,0]               expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: LC example 3 — steep ascent then descent
    {
        vector<int> arr = {0,10,5,2};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[0,10,5,2]              expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: minimum length (3 elements) — peak in the middle
    {
        vector<int> arr = {3,5,4};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[3,5,4]                 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: peak at index n-2
    {
        vector<int> arr = {1,2,4,3};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[1,2,4,3]               expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: peak immediately after the first element
    {
        vector<int> arr = {1,3,2};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[1,3,2]                 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: longer mountain — peak in the middle
    {
        vector<int> arr = {1,2,3,4,5,3,1};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[1,2,3,4,5,3,1]         expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: negative values — peak still found by slope comparison
    {
        vector<int> arr = {-5,-3,-1,-2,-4};
        int got = sol.peakIndexInMountainArray(arr);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  arr=[-5,-3,-1,-2,-4]        expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
