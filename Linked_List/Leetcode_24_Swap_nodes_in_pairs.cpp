/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without
modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
    Input: head = [1,2,3,4]
    Output: [2,1,4,3]

Example 2:
    Input: head = []
    Output: []
    
Example 3:
    Input: head = [1]
    Output: [1]
 
###Constraints:
    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
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
    ListNode* swapNodes(ListNode* head)
    {
        if (head == NULL || head->next == NULL)  
            return head;

        ListNode *node1 = head,  *node2 = head->next;
        ListNode * next = swapNodes(head->next->next);
        node2->next = node1;
        node1->next = next;

        return node2;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)  
            return head;

        return swapNodes(head);
    }
};

//Other way to use recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)  
            return head;

        ListNode *temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};

// Without recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)  
            return head;

        ListNode *res = new ListNode();
        res->next = head;
        ListNode* curr = res;

        while (curr && curr->next && curr->next->next)
        {
            ListNode * node1 = curr->next;        //node1 - 1
            ListNode * node2 = curr->next->next;  //node2 - 2
            
            node1->next = node2->next;      // 1-3-4
            node2->next = node1;            // 2-1-3-4
            curr->next = node2;             // res-2-1-3-4
            curr = node1;                   // curr = 1
        }
        return res->next;
    }
};