
# Problem Statement :  Subarray Product Less Than K
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

**Example 1:**
    
    Input: nums = [10,5,2,6], k = 100
    
    Output: 8
    
    Explanation: The 8 subarrays that have product less than 100 are:
    
    [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

**Example 2:**
    
    Input: nums = [1,2,3], k = 0
    
    Output: 0
 

## Constraints:
- 1 <= nums.length <= 3 * 10^4
- 1 <= nums[i] <= 1000
- 0 <= k <= 10^6

## Approach 
### Using Sliding windows TC = O(N) SC = O(1)
- Solution Link : https://leetcode.com/problems/subarray-product-less-than-k/submissions/1906261050/
  
- Maintain a window [left, right] such that the product of all elements in this window is < k.
- Expand right step by step, multiplying prod by nums[right].
- If the product becomes >= k, shrink from the left (divide by nums[left] and move left forward) until the window again satisfies prod < k.
- For each position of right, once the window is valid, all subarrays ending at right and starting anywhere from left to right are valid.
- That adds (right - left + 1) new subarrays to the count.
