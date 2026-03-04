# Problem Statement : Count of Smaller Numbers After Self
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

**Example 1:**

    Input: nums = [5,2,6,1]
    Output: [2,1,1,0]
    Explanation:
    To the right of 5 there are 2 smaller elements (2 and 1).
    To the right of 2 there is only 1 smaller element (1).
    To the right of 6 there is 1 smaller element (1).
    To the right of 1 there is 0 smaller element.

**Example 2:**

    Input: nums = [-1]
    Output: [0]

**Example 3:**

    Input: nums = [-1,-1]
    Output: [0,0]
 
## Constraints:

- 1 <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4

## Approach:
### Naive Solution : TC = O(N^2) , SC = O(1)  (It wont pass Leetcode due to TC)
- Traverse the array from left to right.
- For each ith element, traverse the right side of it (i+1 to n - 1) and keep counting the no. elements > nums[i]
- store the count value res[i]
- return res

### Binary Search Solution : TC = O(N^2) , SC = O(N)  (It wont pass Leetcode due to TC)

-  Traverse the array from right to left (i : n-1 to 0)
-  Maintain a sorted array in which the index of element will implies the no. of smaller elements to the right side
-  Apply binary search [0 to sorted_array.size() - 1] to find out the index where elements needs to be inserted in sorted array.
    - while low <= high :
    
            => compute mid and treat the element to be inserted as target
            => if sorted[mid] >= target :  save mid as possible answer and keep seraching left to get minimum index , high = mid - 1
            => if sorted[mid] < target  :  discard that half ans keep seraching right for index , low = mid + 1

    - return ans
- insert the nums[i] to sorted[index] and increase the length of sorted array
- fill the index as result at res[i] 
- return res


### Merge sort counting : TC = O(N Log N), SC = O(N)  (It will pass Leetcode )
- Solution Link : https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/1937425734/
**Idea** 
- Use merge sort and Count how many right-side elements move before left-side elements
- Merge sort:
    - Divides the array into halves (left half and right half)
    - Sorts each half
    - Merges the halves


**Algo**
- for each nums[i], count the number of elements to its right that are smaller.
- Merge sort splits the array into halves:

        Left half contains elements that were earlier in the original array
        Right half contains elements that were later in the original array

- While merging two sorted halves: count happens here

    - If an element from the right half is smaller, it gets placed first.
    - Finally place an element from the left half, the number of right-half elements already placed equals the count of smaller elements after it (because those right elements    
      originally occurred after it in the array).

- Store (value, originalIndex) to update the correct answer slot.






