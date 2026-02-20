# Problem Statement

Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.
You may assume that each input would have exactly one solution.

**Example 1:**

    Input: nums = [-1,2,1,-4], target = 1
    Output: 2
    Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

**Example 2:**

    Input: nums = [0,0,0], target = 1
    Output: 0
    Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
    
## Constraints:

- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -10^4 <= target <= 10^4

## Approach 
### Using two pointer inside a loop
- Sort the array in ascending order
- Traverse the array from left to right to get possible triplets i => 0 to n-3
- maintain  diff between target and triplet's sum , left and right pointers : left => i + 1 and right => n-1
  
      while left < right  =>  compute sum of triplets and compare with target
                          =>  if sum == target :  return sum 
                          =>  else compare absolute difference between sum and target  with previous absolute diff 
                                          : if previous absolute diff is greater : update diff and store sum as ans
                          => compare sum with target
                                          : if sum > target ->  move right pointer 
                                        : else -> move left pointer 

- return ans as 
