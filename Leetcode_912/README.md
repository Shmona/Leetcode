# Problem Statement :  Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

**Example 1:**

    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
    Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

**Example 2:**

    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]
    Explanation: Note that the values of nums are not necessarily unique.
 
## Constraints:

- 1 <= nums.length <= 5 * 10^4
- -5 * 10^4 <= nums[i] <= 5 * 10^4

## Approach :
### using quick sort : TC = O(N Log N) (worst case : O(N^2)),  SC = O(1)  => Won't pass Leetcode due to TLE
- Solution Link : https://leetcode.com/problems/sort-an-array/submissions/1950763931/

- Choose a pivot element.
- Partition the array such that:

    Elements ≤ pivot are on the left
    Elements > pivot are on the right

- Recursively apply Quick Sort to the left and right subarrays.
- The pivot ends up in its final sorted position after each partition.

### using priority queue : TC = O(N Log N),  SC = O(N)
- Solution Link : https://leetcode.com/problems/sort-an-array/submissions/1728115440/

- Create a max-heap and Insert all elements into a max‑heap.
- Repeatedly extract the maximum element.
- Place extracted elements back into the array from right to left.
