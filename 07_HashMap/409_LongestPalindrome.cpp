#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(int i = 0; i<s.size(); i++)
        f[s[i]]++;
        bool add = false;
        int result = 0;
        for(auto i :f)
        {
            int value = i.second;
            if(value%2==0)
                result+=value;
            else
            {
                result += value - 1;
                add = true;
            }
        }
            if(add==true)
            result++;
        return result;      
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: standard LC example
    {
        int got = sol.longestPalindrome("abccccdd");
        int exp = 7;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"abccccdd\"     expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: single char
    {
        int got = sol.longestPalindrome("a");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"a\"            expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: case-sensitive mix
    {
        int got = sol.longestPalindrome("Aa");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"Aa\"           expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: all same
    {
        int got = sol.longestPalindrome("aaaa");
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"aaaa\"         expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: all unique
    {
        int got = sol.longestPalindrome("abcde");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"abcde\"        expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: all even pairs
    {
        int got = sol.longestPalindrome("aabbcc");
        int exp = 6;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"aabbcc\"       expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: odd counts, one center
    {
        int got = sol.longestPalindrome("aaabbb");
        int exp = 5;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"aaabbb\"       expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: even counts case-sensitive
    {
        int got = sol.longestPalindrome("AaBb");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  s=\"AaBb\"         expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
