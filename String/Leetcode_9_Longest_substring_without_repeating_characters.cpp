/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
###Constraints:
    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int len = s.length();
        if(len == 1)
            return 1;

        unordered_set<char> set;
        int res = 0;
        int left = 0, right = 0;

        while (left < len && right < len)
        {
            if(set.find(s[right]) == set.end()) 
			{
				set.insert(s[right++]); 
				res = max(res, right-left); 
			}
			else
				set.erase(s[left++]);
        }
        return res;
    }
};