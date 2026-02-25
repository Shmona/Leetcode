#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int l1 = s.length();
        int l2 = t.length();

        if(l2 > l1)
            return "";
        unordered_map<char, int> m1, m2;

        for (auto x : t)
            m2[x]++;

        int left = 0, count = 0;
        int ans = INT_MAX;
        int start = 0;

        for (int right = 0; right < l1; right++)
        {
            char ch = s[right];
            m1[ch]++;
            if (m2.find(ch) != m2.end() && m1[ch] == m2[ch])
                count++;
            
            while (count == m2.size())
            {
                if (right - left + 1 < ans)
                {
                    ans = right - left + 1;
                    start = left;
                }
                char d = s[left];
                m1[d]--;
                if (m2.find(d) != m2.end() && m1[d] < m2[d] )
                    count--;

                left++;
            }
        }
                
        if(ans == INT_MAX)
            return "";
        else
            return s.substr(start, ans);
        
    }
    string minWindow_ASCII(string s, string t)
    {
        int l1 = s.length();
        int l2 = t.length();

        if ( l2 > l1 )
            return "";
        
        vector<int> m1(123, 0), m2(123,0);

        for (auto x : t)
            m2[(unsigned int)x]++;
        
        
        int distinct = 0;
        for ( int i = 0; i < 123; i++)
        {
            if (m2[i])
                distinct++;
        }
        
        int left = 0, ans = INT_MAX;
        int start = 0, count = 0;

        for ( int right = 0; right < l1; right++)
        {
            int c = (unsigned int)s[right];
            m1[c]++;

            if (m2[c] && m2[c] == m1[c])
                count++;
            
            while(count == distinct)
            {
                if (right - left + 1 < ans )
                {
                    ans = right - left + 1;
                    start = left;
                }
                int d = (unsigned int)s[left];
                m1[d]--;

                if (m2[d] && m1[d] < m2[d])
                    count--;
                left++;
            }
        }
        if (ans == INT_MAX)
            return "";
        else
            return s.substr(start, ans);
    }
};

int main()
{
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << "\n"; // "BANC"
    cout << sol.minWindow_ASCII("ADOBECODEBANC", "ABC") << "\n";

    cout << sol.minWindow("a", "a") << "\n";               // "a"
    cout << sol.minWindow_ASCII("a", "a") << "\n";
    
    cout << sol.minWindow("a", "aa") << "\n";              // ""
    cout << sol.minWindow_ASCII("a", "aa") << "\n";

    cout << sol.minWindow("aa", "aa") << "\n";             // "aa"
    cout << sol.minWindow_ASCII("aa", "aa") << "\n";

    cout << sol.minWindow("ab", "A") << "\n";              // ""
    cout << sol.minWindow_ASCII("ab", "A") << "\n";

    cout << sol.minWindow("bba", "ab") << "\n";            // "ba"
    cout << sol.minWindow_ASCII("bba", "ab") << "\n";

    cout << sol.minWindow("cabefgecdaecf", "cae") << "\n"; // "aec"
    cout << sol.minWindow_ASCII("cabefgecdaecf", "cae") << "\n";
    return 0;
}
