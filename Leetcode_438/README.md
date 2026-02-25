# Problem Statement :   Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

**Example 1:**

    Input: s = "cbaebabacd", p = "abc"
    Output: [0,6]
    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".

**Example 2:**

    Input: s = "abab", p = "ab"
    Output: [0,1,2]
    Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".
 

## Constraints:

-  1 <= s.length, p.length <= 3 * 10^4
-  s and p consist of lowercase English letters.

## Approach 
### Using Sliding Window + Frequency Count :  TC = O(N)  SC = O(1)
- Solution Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/1910218264/
  
- Build a frequency map of characters in p → m1.
- Sliding window over s
    - Use two pointers left and right to maintain a window of size at most |p| over s. Keep a frequency map of the window → m2.
- Track exact matches via count
    - Maintain a count of how many distinct characters currently have exact matching frequency between m2 and m1.
- When window size equals |p|
    - If count == m1.size() (i.e., all distinct characters match), then the window is an anagram → push left into res.
- Slide the window
    - Add s[right] (expand right)
    - If window exceeds length |p|, remove s[left] (shrink left) and adjust count and m2.
