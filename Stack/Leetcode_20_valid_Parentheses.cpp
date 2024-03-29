/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:
    Input: s = "()"
    Output: true

Example 2:
    Input: s = "()[]{}"
    Output: true

Example 3:
    Input: s = "(]"
    Output: false
 
###Constraints:
    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int i = 0;
        while (i < s.length())
        {
            if (s[i] == ')'  && st.size() > 0 && st.top() == '(')
                st.pop();
            else if (s[i] == '}' && st.size() > 0 && st.top() == '{')
                st.pop();
            else if (s[i] == ']' && st.size() > 0 && st.top() == '[')
                st.pop();
            else 
                st.push(s[i]);

            i++;
        }
        if (st.size() == 0)
            return true;
        else
            return false;
    }
};