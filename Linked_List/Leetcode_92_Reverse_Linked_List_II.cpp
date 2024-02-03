/*
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
    Input: head = [1,2,3,4,5], left = 2, right = 4
    Output: [1,4,3,2,5]

Example 2:
    Input: head = [5], left = 1, right = 1
    Output: [5]

###Constraints:
    The number of nodes in the list is n.
    1 <= n <= 500
    -500 <= Node.val <= 500
    1 <= left <= right <= n
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        
        ListNode *prev = head, *curr = head;

        int count = 1;
        while(curr && count < left)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        ListNode* start = curr; 
        ListNode *next = NULL, *rev_head= NULL;

        while (start && count <= right)
        {
            next = start->next;
            start->next = rev_head;
            rev_head = start;
            start = next;
            count++;
        }
        curr->next = next;
        if (left == 1)  // first node is considered in reversal
            return rev_head;
        else
            prev->next = rev_head;
        return head;  
    }
};