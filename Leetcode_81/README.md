
# Problem Statement :  Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.


**Example 1:**

    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true

**Example 2:**

    Input: nums = [2,5,6,0,0,1,2], target = 3
    Output: false
 
## Constraints:
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- nums is guaranteed to be rotated at some pivot.
- -10^4 <= target <= 10^4
 
    Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

## Approach 
### Using Binary Search  TC = O(N)  => worst case , SC = O(1)
- Solution Link :  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/1928345012/
  
- Since the array id rotated one, so there are two sorted half
- Find the index from where its been rotated => k  (consider duplicates too as nums[k] <= nums[k+1])
- We have two sorted halves :  left half => 0 to k ,   right half => k + 1 to n - 1
- if target lies in left half i.e target <= nums[0] && nums[k] >= target  
    - do binary search in left half (considering low = 0, high = k)

- if target lies in right half i.e target >= nums[k + 1] && nums[n-1] >= target  
    - do binary search in left half (considering low = k + 1, high = n-1)
