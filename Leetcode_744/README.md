# Problem Statement :  Find Smallest Letter Greater Than Target
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. 
There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. 
If such a character does not exist, return the first character in letters.

**Example 1:**

    Input: letters = ["c","f","j"], target = "a"
    Output: "c"
    Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

**Example 2:**

    Input: letters = ["c","f","j"], target = "c"
    Output: "f"
    Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

**Example 3:**

    Input: letters = ["x","x","y","y"], target = "z"
    Output: "x"
    Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
 
## Constraints:
- 2 <= letters.length <= 10^4
- letters[i] is a lowercase English letter.
- letters is sorted in non-decreasing order.
- letters contains at least two different characters.
- target is a lowercase English letter.

## Approach:

### Naive Solution :  TC = O(N) , SC = O(1)
- Solution Link : https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/1934444915/

- Traversed through given array letters from left to right
- if letter[i] > target :  return letter[i]
- if none of the letter is greater than target then return first letter : letters[0]

### Binary Search Solution :  TC = O(Log N) , SC = O(1)
- Solution Link : https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/1934422868/

- Apply binary search for letter which is strictly greater than target letter 
- low = 0 , high = n-1
- while low <= high :

      => compute mid and compare it with target
      => if letters[mid] > target  : it could be potential answer, keep looking left to get first smallest letter: high = mid - 1
      => if letters[mid] <= target :  discard this part and look into right half :  low = mid + 1 

: Return letters[low%n] as low points to the first index where letters[i] > target
