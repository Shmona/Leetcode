/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

Example 2:
    Input: head = [1], n = 1
    Output: []

Example 3:
    Input: head = [1,2], n = 1
    Output: [1]

###Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;

        //calculate the length of linked list
        while (temp)
        {
            len++;
            temp = temp->next;
        }

        if ( n == len)
        {
            head = head->next;
            return head;
        }

        
        int i = 1;
        temp = head;
        while (i < (len - n))
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        
        return head;
    }
};

//USING TWO POINTER : IN ONE PASS
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *curr = head, *temp = head;

        for (int i = 0; i < n; i++) 
            temp = temp->next;

        if (temp == NULL) 
            return head->next;
        
        while (temp->next != NULL) 
        {
            temp = temp->next;
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};