# Problem Statement 
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

        [4,5,6,7,0,1,2] if it was rotated 4 times.
        [0,1,2,4,5,6,7] if it was rotated 7 times.
        Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

**Example 1:**

    Input: nums = [3,4,5,1,2]
    Output: 1
    Explanation: The original array was [1,2,3,4,5] rotated 3 times.

**Example 2:**

    Input: nums = [4,5,6,7,0,1,2]
    Output: 0
    Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

**Example 3:**

    Input: nums = [11,13,15,17]
    Output: 11
    Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 
## Constraints:

- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- All the integers of nums are unique.
- nums is sorted and rotated between 1 and n times.

## Approach 
IDEA :  Since given array is rotated by k times, there are two parts which are sorted. We need to find the part having original (before rotation) nums[0]

**Naive Solution : TC = O(N), O(1)**

- if n == 1 (base case) : return nums[0]
- identify whether array is rotated or not by comparing first and last element
    - if nums[0]  > nums[n-1]  => 2nd half has minimum element (nums[0] before rotation)
        - Traverse array from end k => n - 1 
        - while (k > 0 && nums[k] > nums[k-1])  , keep decrementing k 
        - return nums[k]

    - Else return nums[0]  as array is same as original after rotation

**Using Binary Search TC = O(Log N) SC = O(1)**

- Maintain two pointers pointing to extreme ends low => 0 , high => n - 1
- While ( low < high ) :

    - compute mid and compare nums[mid] with nums[high]
    - if nums[mid] > nums[high]  => mininum is in right half,  skip left half  :   move lower pointer to right half =>  low = mid + 1
    - if nums[mid] < nums[high]  => mininum is in left half,  skip right half  :   move high pointer to left half =>  high = mid
    
- return nums[low]

