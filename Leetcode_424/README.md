# Problem Statement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

**Example 1:**

        Input: s = "ABAB", k = 2
        Output: 4
        Explanation: Replace the two 'A's with two 'B's or vice versa.

**Example 2:**

        Input: s = "AABABBA", k = 1
        Output: 4
        Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
        The substring "BBBB" has the longest repeating letters, which is 4.
        There may exists other ways to achieve this answer too.
        
## Constraints:
- 1 <= s.length <= 10^5
- s consists of only uppercase English letters.
- 0 <= k <= s.length

##  Approach : (Sliding window + Max Frequency)
- Maintain a window [left, right], frequency array of size 26 to count uppercase characters in the current window
- Maintain max_count: the maximum frequency of any single character seen in the window so far
- Expand the window by moving right and updating character counts
- If the number of replacements needed exceeds k -> window_size - max_count > k:
        - Decrease the count of s[left]
        - Shrink the window by moving left
- Update ans = max(ans, window_size)
