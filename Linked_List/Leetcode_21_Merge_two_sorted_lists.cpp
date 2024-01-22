/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

Example 2:
    Input: list1 = [], list2 = []
    Output: []

Example 3:
    Input: list1 = [], list2 = [0]

###Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res; 
        ListNode * temp = &res;

        while (list1 || list2)
        {
            if(list1 && list2)
            {
                if (list1->val <= list2->val)
                {
                    temp->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else
                {
                    temp->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                temp = temp->next;
            }
            else if (list1 && (list2 == NULL))
            {
                temp->next = new ListNode(list1->val);
                temp = temp->next;
                list1 = list1->next;
            }
            else if (list2 && (list1 == NULL))
            {
                temp->next = new ListNode(list2->val);
                temp = temp->next;
                list2 = list2->next;
            }
        }
        return res.next; 
    }
};

/*
USING TWO POINTERs : In place merging
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *temp = list1;
        if(list1->val > list2->val)
        {
            temp = list2;
            list2 = list2->next;
        }
        else
            list1 = list1->next;

        ListNode * curr = temp;
        while (list1 && list2)
        {
            if(list1 && list2)
            {
                if (list1->val < list2->val)
                {
                    curr->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    curr->next = list2;
                    list2 = list2->next;
                }
                curr = curr->next;
            }
        }
        if (list1)
            curr->next = list1;
        else 
            curr->next = list2;

        return temp; 
    }
};

/*
RECURSIVE APPROACH
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if(list1->val > list2->val)
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
    }
};