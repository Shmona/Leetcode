#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int l1 = s.length();
        int l2 = p.length();
        vector<int> res;

        if (l2 > l1)
            return res;
        
        unordered_map<char, int> m1, m2;
        for (auto x : p)
            m1[x]++;
        
        int left = 0;
        int count = 0;

        for (int right = 0; right < l1; right++)
        {
            char ch = s[right];
            m2[ch]++;
            if (m1.find(ch) != m1.end() && m1[ch] == m2[ch])
                count++;
            
            while (right - left + 1 > l2)
            {
                char d = s[left];
                left++;

                if((m1.find(d) != m1.end()) && m1[d] == m2[d] )
                    count--;
                
                m2[d]--;
                if (m2[d] == 0) 
                    m2.erase(d);
            }
            if (right - left + 1 == l2 && count == m1.size())
                    res.push_back(left);
        }
        return res;
    }
};

int main()
{
    string s1 = "cbaebabacd", p1 ="abc";
    Solution  sol;
    vector<int> res =  sol.findAnagrams(s1,p1);                                          // expects [0,6]
    cout << " Starting index of all possible anagram of " << p1 << " in " << s1 << endl;
    for (auto x : res)
        cout << x << " ";
    
    string s2 ="abab", p2 ="ab";
    vector<int> res1 =  sol.findAnagrams(s2, p2);                                       // expects [0,1,2]
    cout << " \n Starting index of all possible anagram of " << p2 << " in " << s2 << endl;
    for (auto x : res1)
        cout << x << " ";

    string s3 ="a", p3 ="ab";
    vector<int> res2 =  sol.findAnagrams(s3, p3);                                       // expects []
    cout << " \n Starting index of all possible anagram of " << p3 << " in " << s3 << endl;
    for (auto x : res2)
        cout << x << " ";

    return 0;
}
