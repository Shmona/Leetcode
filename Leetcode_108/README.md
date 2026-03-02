# Problem Statement : Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

**Example 1:**

    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted:

**Example 2:**

    Input: nums = [1,3]
    Output: [3,1]
    Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
    
## Constraints:
- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums is sorted in a strictly increasing order.

## Approach:

**IDEA**:  A sorted array has a natural BST structure:
    -  The middle element becomes the root (to keep the tree balanced)
    -  Left half becomes the left subtree
    -  Right half becomes the right subtree
    -  This repeats recursively for each subarray.

### Using Recursive Divide & Conquer approach :  TC = O(N), SC = O(Log N)
- Solution Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1935511935/

- Choose the mid index mid = low + (high - low) / 2
- Create a node with value nums[mid]
- Recursively build:

        left subtree from low → mid - 1
        right subtree from mid + 1 → high# Problem Statement :
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

**Example 1:**

    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted:

**Example 2:**

    Input: nums = [1,3]
    Output: [3,1]
    Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
    
## Constraints:
- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums is sorted in a strictly increasing order.

## Approach:

**IDEA**:  A sorted array has a natural BST structure:

      -  The middle element becomes the root (to keep the tree balanced)
      -  Left half becomes the left subtree
      -  Right half becomes the right subtree
      -  This repeats recursively for each subarray.

### Using Recursive Divide & Conquer approach :  TC = O(N), SC = O(Log N)
- Solution Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1935511935/

- Choose the mid index mid = low + (high - low) / 2
- Create a node with value nums[mid]
- Recursively build:

        left subtree from low → mid - 1
        right subtree from mid + 1 → high

- if low > high, return nullptr

- if low > high, return nullptr

