
# Problem Statement : Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

**Example 1:**

    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

**Example 2:**

    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4
    
## Constraints:

- 1 <= k <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
 
## Approach :
### Naive Solution : TC = O(N Log N) , SC = O(1)
- Solution Link :  https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1949971886/

- Sort the array in ascending order and return (n - k)th element

### Using priority queue :  TC = O(N Log K) , SC = O(K)
- Solution Link :  https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1949979723/

- Create a min-heap of size k
- Traverse the array from left to right and Push elements one by one
- If heap size exceeds k, pop the smallest
- Top of heap = k‑th largest element

### Using QuickSelect (Divide and partition) : TC =  Avg O(N), Worst O(N^2) ,  SC = O(1)  (Won't pass Leetcode due to Worst case TC )
**IDEA**
- Partition array around a pivot 

        After partitioning,  the pivot is in its final sorted position
        Everything left of pivot ≤ pivot
        Everything right of pivot > pivot
- Recurse only into the side containing k‑th largest


- Solution Link : https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1950003277/

**Partition array around a pivot**
- Chose pivot as the last element 
- Elements ≤ pivot are on the left
- Elements > pivot are on the right
- The pivot reaches its final sorted position.

**Recursion logic**
- Compare pivot index with target index (n − k):

        If equal → answer found
        If smaller → recurse on right subarray
        If larger → recurse on left subarray
