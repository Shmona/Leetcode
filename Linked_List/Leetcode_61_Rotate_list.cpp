/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]

Example 2:
    Input: head = [0,1,2], k = 4
    Output: [2,0,1]
 
###Constraints:
    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 10^9
*/

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

// USING TWO POINTER
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(k==0 || head == NULL)
            return head;

        int len = 0;
        ListNode * temp = head, *curr= head;

        while(temp)
        {
            len++;
            temp = temp->next;
        }
        k= k%len;

        if(k==0)
            return head;
        temp = head;

        for (int i = 0; i < k; i++)
            temp = temp->next;
        
        while (temp->next != NULL) 
        {
            temp = temp->next;
            curr = curr->next;
        }
        temp->next = head;
        head  = curr->next;
        curr->next = NULL;
        
        return head;
    }
};
