
# Problem Statement :  Split Array Largest Sum

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

**Example 1:**

    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

**Example 2:**

    Input: nums = [1,2,3,4,5], k = 2
    Output: 9
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 
## Constraints:
- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 10^6
- 1 <= k <= min(50, nums.length)

## Approach 

**IDEA** :  

    - Guess the minimum sum and check if it works

        - For a sum S, can we split nums into at most k subarrays such that each subarray sum ≤ S?
        - If yes, then S might be the answer (try smaller).
        - If no, S is too small (we need a larger limit).


### Using Monotonic binary search : TC =  O(N Log R) where R is the range, SC = O(1)
- Solution Link : https://leetcode.com/problems/split-array-largest-sum/submissions/1932944427/

- Apply binary search over a range [low, high], where
        
        low = max_element(nums)
        high = accumulate(nums)

- While low <= high:

      => Compute mid  and treat it min Sum.
      => if split_needed(mid)  <= k  :  Store mid as a possible answer and look further left to get minimum sum
      => if split_needed(mid)  > k  :   discard that left half and move to right half

- return answer
