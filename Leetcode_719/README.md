# Problem Statement :  Find K-th Smallest Pair Distance
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

**Example 1:**

    Input: nums = [1,3,1], k = 1
    Output: 0
    Explanation: Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.

**Example 2:**

    Input: nums = [1,1,1], k = 2
    Output: 0

**Example 3:**

    Input: nums = [1,6,1], k = 3
    Output: 5
 
## Constraints:
- n == nums.length
- 2 <= n <= 10^4
- 0 <= nums[i] <= 10^6
- 1 <= k <= n * (n - 1) / 2

## Approach :
## using binary search: TC = O(N Log N + N Log R) (Sorting: O(N log N) , Each countPairs(D) check: O(N) Binary search over distance: O(log R) , R is range [0, max-min]), SC = O(1)
- Solution Link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/submissions/1933216398/

- Sort the array and binary search in the distance range [0, max-min].
- while low <= high :
        
        - compute mid and treat it as d
        - count pairs with distance  d using two pointers : countPairs(mid)
            -  if countPairs(mid) >= k  : store mid as a possible answer and search further in left half to get minimum distance
            -  if countPairs(mid) < k   : discard that half and search in right half

**Logic of countPairs(nums, mid, k)**
- use two pointer approach (moving in same direction) , left = 0, right = 1;
- For each right, move left forward until nums[right]-nums[left] <= d.
- Add (right-left) to the count
- return count
