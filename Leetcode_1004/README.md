# Problem Statement  :  Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

**Example 1:**

        Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
        Output: 6
        Explanation: [1,1,1,0,0,1,1,1,1,1,1]
        Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

**Example 2:**

        Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
        Output: 10
        Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
        Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

## Constraints:
- 1 <= nums.length <= 10^5
- nums[i] is either 0 or 1.
- 0 <= k <= nums.length

## Approach (Sliding Window + Max frequency)
**Option 1 :  Counting no. of zeros in the  sliding window**
- Solution Link :  https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1910438058/
  
  - Maintain a window [left, right] and count the number of zeros till zerocount <= k
  - when zerocount > k:
    - If nums[left] == 0, decrement zerocount
    - shrink the window by removing leftmost element
  - ans = max(ans, window_size) where window_size = right - left + 1

**Option 2: Counting no. of ones in the  sliding window**
- Solution Link : https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1910497061/

  - Maintain a window [left, right] and count the number of ones till (window_size - onecount) <= k
  - when (window_size - onecount) > k:
    - If nums[left] == 1, decrement onecount
    - shrink the window by removing leftmost element
  - ans = max(ans, window_size) where window_size = right - left + 1
