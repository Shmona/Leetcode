/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

Example 2:
    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]

###Constraints:
    The number of nodes in the list is in the range [1, 5 * 10^4].
    1 <= Node.val <= 1000
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        //find mid of the linked list
        ListNode* slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;               // 2 , 3
            fast = fast->next->next;         // 3
        }
        ListNode* head2;
        if (fast)                  // for odd no. of nodes
            head2 = slow->next;
        else
            head2 = slow;
    
        stack<ListNode*> st;
        //push second half to stack : top will have last node
        while(head2)
        {
            st.push(head2);
            head2= head2->next;
        }

        ListNode * head1 = head;
        while(st.size())
        {
            head2 = head1->next;         
            head1->next = st.top();
            st.top()->next = head2;

            head1 = head2;
            st.pop();
        }
        slow->next = NULL;
    }
};