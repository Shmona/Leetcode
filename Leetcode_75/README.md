# Problem Statement
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

**Example 2:**

    Input: nums = [2,0,1]
    Output: [0,1,2]
 

## Constraints:
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2.
 
    Follow up: Could you come up with a one-pass algorithm using only constant extra space?

## Approach
**Using three pointers (Dutch Flag)**  TC = O(N)
- maintain 3 pointers pointing to start of 3 partitions (red , white and blue): 

    - left => 0  :  points to the start index where red color (0) needs to be filled
    - mid => 0 : points to the start index where white  color (1) needs to be filled
    - right => n-1 : points to the start index where blue  color (2) needs to be filled

- Traverse the array, left to right(using mid index) , maintaining under (mid <= right)
      
      - if object is red :  
              fill the red partition by swapping nums[mid] with nums[left] 
              increase the pointer of red partition i.e left++
              move to next object i.e mid++
  
      - if object is white :  
              fill the white partition , already in there
              increase the pointer of white partition i.e mid++
  
      - if object is blue :  
              fill the blue partition by swapping nums[mid] with nums[right] 
              increase the pointer of blue partition i.e right--


**Use Sorting** TC = O(NLog N)
- simply sort the array in ascending order
