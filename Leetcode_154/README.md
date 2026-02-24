# Problem Statement : Find Minimum in Rotated Sorted Array II
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

    [4,5,6,7,0,1,4] if it was rotated 4 times.
    [0,1,4,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
You must decrease the overall operation steps as much as possible.


**Example 1:**

    Input: nums = [1,3,5]
    Output: 1

**Example 2:**

    Input: nums = [2,2,2,0,1]
    Output: 0
 

## Constraints:
- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- nums is sorted and rotated between 1 and n times.
 
    Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

## Approach 
**IDEA** 

      - Since given array is rotated by k times, there are two parts which are sorted. We need to find the part having original (before rotation) nums[0]
      - Take care of Duplicates too in every comparision case

**Naive Solution : TC = O(N), O(1)**
- Solution Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/submissions/1928480282/

- if n == 1 (base case) : return nums[0]
- identify whether array is rotated or not by comparing first and last element
    - if nums[0]  >= nums[n-1]  => 2nd half has minimum element (nums[0] before rotation)
        - Traverse array from end k => n - 1 
        - while (k > 0 && nums[k] >= nums[k-1])  , keep decrementing k 
        - return nums[k]

    - Else return nums[0]  as array is same as original after rotation

**Using Binary Search TC = O(Log N) SC = O(1)**
- Solution Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/submissions/1928472835/
  
- Maintain two pointers pointing to extreme ends low => 0 , high => n - 1
- While ( low < high ) :

    - compute mid and compare nums[mid] with nums[high]
    - if nums[mid] == nums[high]  => Skip it by moving high pointer to left => high--
    - if nums[mid] > nums[high]  => mininum is in right half,  skip left half  :   move lower pointer to right half =>  low = mid + 1
    - if nums[mid] < nums[high]  => mininum is in left half,  skip right half  :   move high pointer to left half =>  high = mid
    
- return nums[low]
