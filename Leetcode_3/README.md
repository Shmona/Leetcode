# Problem Statement 
Given a string s, find the length of the longest substring without duplicate characters.

**Example 1:**
  
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
 
**Example 2:**

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

**Example 3:**

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

## Constraints:

- 0 <= s.length <= 5 * 10^4
- s consists of English letters, digits, symbols and spaces.

## Approach 
- Maintain a window s[left .. right].
- Expand the window by moving right one step at a time through the string.
- If the window ever contains a duplicate character => shrink it from the left by moving left forward until the window is valid again.
- At every step, if the window has no duplicates, update the answer with its size: right - left + 1.
