
# Problem Statement : Guess Number Higher or Lower
We are playing the Guess Game. The game is as follows:
- I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

- Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

- You call a pre-defined API int guess(int num), which returns three possible results:

        -1: Your guess is higher than the number I picked (i.e. num > pick).
         1: Your guess is lower than the number I picked (i.e. num < pick).
         0: your guess is equal to the number I picked (i.e. num == pick).

- Return the number that I picked.

**Example 1:**

    Input: n = 10, pick = 6
    Output: 6

**Example 2:**

    Input: n = 1, pick = 1
    Output: 1

**Example 3:**

    Input: n = 2, pick = 1
    Output: 1
 
## Constraints:
- 1 <= n <= 2^31 - 1
- 1 <= pick <= n

## Approach 
### using binary Search TC = O(Log N), SC = O(1)
- Solution Link :  https://leetcode.com/problems/guess-number-higher-or-lower/submissions/1928076535/
  
- Take two pointers to define the extremes of possible range of numbers to be picked,  low = 1, high = n
- while low <= high :
  
      - compute mid and guess whether mid is the picked number or not
      - if mid is the picked number i.e guess(mid) == 0 => return mid
      - if mid is not the picked number 
              - if  guess(mid) == 1  :  guess(mid) is lower than the picked number(Target) => move the low pointer to mid + 1
              - if  guess(mid) == -1  : guess(mid) is higher than the picked number(Target) => move the high pointer to mid - 1
