/*
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int N = lists.size();

        if(lists.empty())
            return NULL;
    
        while (lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin()); // delete lists[0]
            lists.erase(lists.begin()); // delete lists[1]
        }
        return lists[0];
        
    }
};