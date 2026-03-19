# Problem Statement :  Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

**Example 1:**

    Input: head = [4,2,1,3]
    Output: [1,2,3,4]

**Example 2:**

    Input: head = [-1,5,3,4,0]
    Output: [-1,0,3,4,5]

**Example 3:**

    Input: head = []
    Output: []
 
## Constraints:

- The number of nodes in the list is in the range [0, 5 * 10^4].
- -10^5 <= Node.val <= 10^5
 
    Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

## Approach :
### Naive Solution :  TC = O(N^2),  SC = O(1)  => Wont pass Leetcode due to TLE
- Solution Link :  https://leetcode.com/problems/sort-list/submissions/1950785095/

- For each curr node, you:

    Scan the rest of the list to find the smallest node (swap_node)
    Swap swap_node->val with curr->val
    Move curr forward

### Using Merge sort : TC = O(N Log N), SC = O(Log N)
- Solution Link : https://leetcode.com/problems/sort-list/submissions/1952812062/

- Find the midpoint of the linked list using slow/fast pointers

        slow moves 1 step
        fast moves 2 steps
        when fast reaches the end, slow is near the middle

- Split the list into two halves

        Left half: head → mid
        Right half: mid->next → end
        
    **Important: break the link**

            mid->next = nullptr
            so the two halves become independent lists

- Recursively sort each half
- Merge the two sorted halves

      Use a standard merge step (like merging two sorted arrays)
      Pick smaller head each time and relink pointers
