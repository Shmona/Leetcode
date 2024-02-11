/*
Given a string s, reverse the order of characters in each word within a sentence while still 
preserving whitespace and initial word order.

Example 1:
    Input: s = "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
    Input: s = "Mr Ding"
    Output: "rM gniD"
 
###Constraints:
    1 <= s.length <= 5 * 10^4
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.
*/

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        while(end < s.length())
        {
            if(s[end] == ' ')
            {
                reverse(s.begin() + start, s.begin()+ end);
                start = end + 1;
            }

            if ( end == s.length() - 1)
                reverse(s.begin() + start, s.end());
            end++; 
        }
        return s; 
    }
};