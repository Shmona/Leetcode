#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    } 
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next) 
    {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    // Naive solution
    ListNode* sortList(ListNode* head) {

        ListNode * curr = head;

        while (curr)
        {
            ListNode * temp = curr->next;
            ListNode * swap_node = curr;
            while(temp)
            {
                if (temp->val < swap_node->val)
                    swap_node = temp;
                temp = temp->next;
            }
            swap(swap_node->val, curr->val);
            curr = curr->next;
        }
        return head;
    }
    // Using Merge Sort
    ListNode* sortList_MS(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *mid = getMid(head);
        ListNode *right = mid->next;
        mid->next = nullptr;

        ListNode *leftsorted = sortList_MS(head);
        ListNode *rightsorted = sortList_MS(right);

        return mergeList(leftsorted, rightsorted);
    }
private:
    ListNode * getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeList(ListNode *left, ListNode * right)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (left && right)
        {
            if (left->val <= right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        tail->next = (left ? left : right);
        return dummy.next;
    }
};

void printList(ListNode *head)
{
    if (head == nullptr)
        return;

    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

ListNode* buildList(vector<int>& v)
{
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int x : v) 
    {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

int main()
{
    Solution sol;
    vector<int> v = {4,2,1,3};
    ListNode *head = buildList(v);
    cout<< "\n List before sorting :  ";
    printList(head);
    head = sol.sortList(head);
    cout<< "\n List after sorting :  ";
    printList(head);

    vector<int> v1 = {-1,5,3,4,0};
    ListNode *head1 = buildList(v1);
    cout<< "\n List before sorting :  ";
    printList(head1);
    head1 = sol.sortList_MS(head1);
    cout<< "\n List after sorting :  ";
    printList(head1);

    return 0;
}
