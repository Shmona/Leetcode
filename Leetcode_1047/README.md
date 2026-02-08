# Problem Statement 
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

**Example 1:**

    Input: s = "abbaca"
    Output: "ca"
    Explanation: 
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

**Example 2:**

    Input: s = "azxxzy"
    Output: "ay"
 
## Constraints:

- 1 <= s.length <= 10^5
- s consists of lowercase English letters.

## Approach 1 : Using string as a stack  
-  Traverse the string s from left to right and build a result string res:
-  If res is empty, push the current character s[i] into res.
-  Otherwise, compare the rightmost character of res (res.back()) with s[i]:
   - if res.back() == s[i]: pop the rightmost character from res (this removes the adjacent duplicate pair)
   - Else: push s[i] into res.


## Approach 2 : Using Stack<char>
- Traverse the string s from left to right, maintain stack<char> such that
  - if stack is not empty or st.top() == s[i]  => st.pop()
  - else insert s[i] => st.push(s[i])

-  store the res as res = st.top() + res till stack is empty
