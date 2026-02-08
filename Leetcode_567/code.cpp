#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if ( l1 > l2 )
            return false;
        
        unordered_map <char, int> m1 , m2;
        for (auto x : s1)
            m1[x]++;

        int count = 0;              
    
        int left = 0;
        for (int right = 0; right < l2; right++)
        {
            char c = s2[right];
            m2[c]++;

            if((m1.find(c) != m1.end()) && m1[c] == m2[c] )
                count++;
            
            while (right - left + 1 > l1)
            {
                char d = s2[left];
                left++;
                if((m1.find(d) != m1.end()) && m1[d] == m2[d] )
                    count--;
                
                m2[d]--;
                if (m2[d] == 0) 
                    m2.erase(d);

            }

            if (right - left + 1 == l1 && count == m1.size())
                return true;
        }
        return false;
    }
};

int main()
{
    string s1 = "ab", s2 =  "eidbaooo", s3 ="eidboaoo";
    Solution sol;
    cout << sol.checkInclusion(s1, s2) << endl;
    cout << sol.checkInclusion(s1, s3) << endl;

    return 0;
}
