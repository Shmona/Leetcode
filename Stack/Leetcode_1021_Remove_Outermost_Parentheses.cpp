/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B 
are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to 
split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, 
where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:
    Input: s = "(()())(())"
    Output: "()()()"
    Explanation: 
    The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
    After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
    Input: s = "(()())(())(()(()))"
    Output: "()()()()(())"
    Explanation: 
    The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
    After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
    Input: s = "()()"
    Output: ""
    Explanation: 
    The input string is "()()", with primitive decomposition "()" + "()".
    After removing outer parentheses of each part, this is "" + "" = "".
 

###Constraints:
    1 <= s.length <= 10^5
    s[i] is either '(' or ')'.
    s is a valid parentheses string.
*/
//Using Stack 
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st; //push when opening bracket pop when closing bracket
        for (auto x : s)
        {
            if ( x == '(')
            {
                if (st.size() > 0)
                    res += x;
                st.push(x);
            }
            else if ( x == ')')
            {
                if (st.size() > 1)
                    res += x;
                st.pop();
            }
        }
        return res;
    }
};

//Naive approach
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int flag = 0;  //+1 when opening bracket -1 when closing bracket
        for (auto x : s)
        {
            if ( x == '(' && flag++ > 0)
                res += x;
            if ( x == ')' && flag-- > 1)
                res += x;
        }
        return res;
    }
};