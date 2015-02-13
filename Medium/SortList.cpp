
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode *vh = new ListNode(0);
    ListNode *t = vh;
    while (l1 != NULL || l2 != NULL)
    {
        ListNode *tmp;
        if (l1 == NULL) tmp = l2, l2 = l2->next;
        else if (l2 == NULL) tmp = l1, l1 = l1->next;
        else
        {
            if (l1->val < l2->val) tmp = l1, l1 = l1->next;
            else tmp = l2, l2 = l2->next;
        }
        t->next = tmp;
        t = t->next;
    }
    return vh->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    fast = sortList(fast);
    slow = sortList(head);
    return merge(fast, slow);
}

int main()
{
    int A[] = {3,2,1};

    ListNode* p = buildListNode(A, 3);
    ListNode *ans = sortList(p);
    printListNode(ans);
}
