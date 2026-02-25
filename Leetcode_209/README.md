# Problem statement  :  Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

**Example 1:**

    Input: target = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: The subarray [4,3] has the minimal length under the problem constraint.

**Example 2:**

    Input: target = 4, nums = [1,4,4]
    Output: 1

**Example 3:**

    Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    Output: 0
 

## Constraints:

- 1 <= target <= 10^9
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^4
 
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

## Approach 
### Using Sliding Windows TC = O(N) , SC = O(1)
- Solution Link :  https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1906509460/
  
- Maintain a window [left, right] and its running sum.
- Expand the window by moving right forward and adding nums[right] to sum.
- Whenever the window sum becomes ≥ target, shrink it from the left to find the shortest possible window that still satisfies the condition:
  
      - Update the answer with the current window length.
      - Subtract nums[left] from sum and increment left.
  
- Continue until right has scanned the entire array.
