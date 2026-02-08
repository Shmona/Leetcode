# Problem Statement

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

**Example 1:**

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

**Example 2:**

    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.

**Example 3:**

    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.
 
## Constraints:
- m == s.length
- n == t.length
- 1 <= m, n <= 105
- s and t consist of uppercase and lowercase English letters.
 

        Follow up: Could you find an algorithm that runs in O(m + n) time?

# Approach

## using Sliding windows + hash map
- Build m2 : frequency map of characters in t.
- Slide a window [left, right] over s, maintaining m1 : frequency map for current window.
- Maintain count: the number of characters for which the window currently satisfies the required frequency (m1[ch] == m2[ch]).
- When count == m2.size() (i.e.all distinct required characters are satisfied), try to shrink from the left to minimize window length while keeping it valid (m1[c] >= m2[c]).
- Track the best (shortest) window seen.

## using Sliding windows + freq map (ASCII)
-   A - Z :  65 to 90 and a - z : 97 to 122 
- build m2[123] => frequency map of characters in t
- Slide a window [left, right] over s, maintaining m1 : frequency map for current window.
- Maintain count: the number of characters for which the window currently satisfies the required frequency (m1[ch] == m2[ch]).
- When count == m2.size() (i.e.all distinct required characters are satisfied), try to shrink from the left to minimize window length while keeping it valid (m1[c] >= m2[c]).
- Track the best (shortest) window seen.


