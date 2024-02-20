/*
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
    Input: l1 = [7,2,4,3], l2 = [5,6,4]
    Output: [7,8,0,7]

Example 2:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [8,0,7]

Example 3:
    Input: l1 = [0], l2 = [0]
    Output: [0]

###Constraints:
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
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
    ListNode* reverselist(ListNode* head)
    {
        if ( head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverselist(l1);
        l2 = reverselist(l2);

        int carry = 0;
        ListNode * res = new ListNode(0);
        ListNode * curr = res;
        while (l1 || l2 || carry)
        {
            int temp = carry;
            if (l1)
            {
                temp += l1->val;
                l1 = l1->next;
            } 
            if(l2)
            {
                temp += l2->val;
                l2 = l2->next;
            } 
            carry = temp/10;
            curr->next = new ListNode (temp%10);
            curr = curr->next;           
        }
        return reverselist(res->next);
    }
};

//Using Stack
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>  s1, s2 ;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        } 
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* curr = NULL;
        int carry = 0;
		while(!s1.empty() || !s2.empty())
		{
            int temp = carry;
			if(!s1.empty())
			{
				temp+=s1.top();
				s1.pop();
			}
		    if(!s2.empty())
			{
				temp+=s2.top();;
				s2.pop();
			}
            carry = temp/10;
            ListNode* head = new ListNode (temp%10);
            head->next = curr;
            curr = head;
        }
        if (carry != 0)
        {
            ListNode* head = new ListNode(carry);
            head->next = curr;
            curr = head;
        }
        return curr;
    }
};