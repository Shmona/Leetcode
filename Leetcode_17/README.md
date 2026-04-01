# Problem Statement : Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
![Alt text](image.png)


**Example 1:**

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

**Example 2:**

    Input: digits = "2"
    Output: ["a","b","c"]
 
## Constraints:

- 1 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].

## Approach :
### Using Backtracking (DFS) : TC = O(4^N) , SC = O(N)
- Solution Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1958755679/

- use recursive backtracking to build combinations character‑by‑character.
  
**IDEA**
- At each digit index:
  
        - Try all possible letters for that digit
        - Append one letter to the current string
        - Recurse to the next digit
        - Backtrack by removing the last letter

**Steps**
- Create a digit‑to‑letters mapping using unordered_map
- Start recursion from index 0 with an empty string
- At each recursion level:

        Get letters for the current digit
        Iterate over them
        Add one letter and recurse

- When index == digits.size(): A full combination is formed then Add it to the result
