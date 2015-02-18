
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    ListNode *vhead = new ListNode(0); // virtual
    vhead->next = head;
    ListNode *prev = NULL, *next = NULL, *end = head;
    ListNode *p = head->next;
    while (p != NULL)
    {
        prev = vhead, next = vhead->next;
        while (next != p && p->val >= next->val)
            next = next->next, prev = prev->next;
        if (next != p)
        {
            end->next = p->next;
            prev->next = p;
            p->next = next;
        }
        else
            end = p;

        p = end->next;
    }

    head = vhead->next;
    return head;
}

int main()
{
    int A[] = {3,4,1};

    ListNode* l = buildListNode(A, 3);

    l = insertionSortList(l);

    printListNode(l);

    return 0;
}
