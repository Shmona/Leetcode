# Problem Statement : Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity. 

**Example 1:**

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

**Example 2:**

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

**Example 3:**

    Input: nums = [], target = 0
    Output: [-1,-1]

## Constraints:
- 0 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
- nums is a non-decreasing array.
- -10^9 <= target <= 10^9

## Approach 
### Naive Solution  TC = O(N) . Sc = O(1)
- Traverse the array from left to right till you reach first occurrence of target 
- Save the index of first occurrence of target 
- Traverse till you get differnt number than target
- Save the index of last occurrence of target


### Binary Search  TC = O(Log N) , SC = O(1)
- idea is to retrive first and last occurrence of target in the given array using binary search algorithm. 

- First occurrence:

        => take two pointers low => 0, high => n-1
        => while (low <= high) :
                    => compute mid and compare nums[mid] with target
                    => if nums[mid]  >= target  
                            :  target lies in left side of mid
                            :  if nums[mid]  == target  => store mid as ans 
                            :  keep searching left side of mid to get first occurrence of target,  high = mid - 1
                    => if nums[mid] < target 
                            :  target lies in right side of mid
                            :  move to right half,  low = mid + 1

- Last occurrence:

        => take two pointers low => 0, high => n-1
        => while (low <= high) :
                    => compute mid and compare nums[mid] with target
                    => if nums[mid]  <= target  
                            :  target lies in right side of mid
                            :  if nums[mid]  == target  => store mid as ans 
                            :  keep searching right side of mid to get last occurrence of target,  low = mid + 1
                    => if nums[mid] > target 
                            :  target lies in left side of mid
                            :  move to left half,  high = mid - 1
