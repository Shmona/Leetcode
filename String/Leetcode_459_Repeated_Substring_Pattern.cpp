/*
Given a string s, check if it can be constructed by taking a substring of it and appending 
multiple copies of the substring together.

Example 1:
    Input: s = "abab"
    Output: true
    Explanation: It is the substring "ab" twice.

Example 2:
    Input: s = "aba"
    Output: false
    
Example 3:
    Input: s = "abcabcabcabc"
    Output: true
    Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 
###Constraints:
1 <= s.length <= 10^4
s consists of lowercase English letters.
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int len = s.length();
        
        for (int i = len/2; i >= 1; i--)
        {
            if (len%i == 0)
            {
                if (s.substr(0, len-i) == s.substr(i))
                    return true;
            }
        }
        return false;
    }
};