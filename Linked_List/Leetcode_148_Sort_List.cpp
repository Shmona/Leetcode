/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
    Input: head = [4,2,1,3]
    Output: [1,2,3,4]

Example 2:
    Input: head = [-1,5,3,4,0]
    Output: [-1,0,3,4,5]

Example 3:
    Input: head = []
    Output: []
 
##Constraints:
The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

//NAIVE APPROACH (using selection sorting by value): Wont pass and throw TLE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode * curr = head, *next = NULL;

        while (curr)
        {
            next = curr->next;
            while (next)
            {
                if (curr->val > next->val)
                    swap(curr->val, next->val);
                next = next->next;
            }  
            curr = curr->next;
        }
        return head;
    }
};