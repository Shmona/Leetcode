# Problem Statement 
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

**Example 1:**

    Input: nums = [1,3,5,6], target = 5
    Output: 2

**Example 2:**

    Input: nums = [1,3,5,6], target = 2
    Output: 1

**Example 3:**

    Input: nums = [1,3,5,6], target = 7
    Output: 4
 
## Constraints:

- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums contains distinct values sorted in ascending order.
- -10^4 <= target <= 10^4


## Approach 
**using binary search for lower bound  TC = O(NLogN), SC = O(1)**
- Take two pointers pointing to ends low = 0, high = n-1

      - while low <= high :
          => compute mid 
          => compare mid value with target
                  : if mid value == target => return mid index
                  : if mid value > target => target is in left side, move the high => mid - 1
                : if mid value <> target => target is in right side, move the low => mid + 1
- return low index as answer
