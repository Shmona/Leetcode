# Problem Statement :  Number of Good Pairs
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

**Example 1:**

    Input: nums = [1,2,3,1,1,3]
    Output: 4
    Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

**Example 2:**

    Input: nums = [1,1,1,1]
    Output: 6
    Explanation: Each pair in the array are good.

**Example 3:**

    Input: nums = [1,2,3]
    Output: 0
    
## Constraints:

 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Approach :
### Naive Solution : TC = O(N^2) , SC = O(N)
- Solution Link : https://leetcode.com/problems/number-of-good-pairs/submissions/1948380655/

- Use two nested loops:

      Outer loop fixes the first index i
      Inner loop tries all indices j > i
      Whenever nums[i] == nums[j], increment the count

- return count


### Using Hash Map : TC = O(N) , SC = O(D)  , D is no. of distinct numbers
- Solution Link : https://leetcode.com/problems/number-of-good-pairs/submissions/1948389540/


- Create a hash map freq to store how many times each number has appeared.
- Initialize count = 0.
- For each number x in nums:

      Add freq[x] to count (new pairs formed with previous xs).
      Increment freq[x].

- Return count.
