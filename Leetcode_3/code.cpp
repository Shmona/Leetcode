#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> st;
        int res = 0;
        int l = s.length();

        int left = 0;
        for ( int right = 0; right < l;  right++)
        {
            while (st.find(s[right]) != st.end())
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    string s1 = "";
    Solution sol;
    cout << "Length of longest Substring in "<< s1  << " is "
         << sol.lengthOfLongestSubstring(s1) << endl; // expects 3

    string s2 = "pwwkew";
    cout << "Length of longest Substring in "<< s2  << " is "
         << sol.lengthOfLongestSubstring(s2) << endl;  // expects 3

    string s3 = "bbbbb";
    cout << "Length of longest Substring in "<< s3  << " is "
         << sol.lengthOfLongestSubstring(s3) << endl;  // expects 1

    return 0;
}
