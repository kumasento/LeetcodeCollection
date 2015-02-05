
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode* deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    ListNode *p, *prev, *next;
    ListNode *vhead = new ListNode(0);
    vhead->next = head;

    p = vhead;
    prev = vhead->next;
    next = vhead->next->next;
    while (prev != NULL)
    {
        next = prev->next;
        if (next != NULL && prev->val == next->val)
        {
            while (next != NULL && prev->val == next->val)
                next = next->next;
            p->next = next;
        }
        else
            p = prev;
        prev = next;
    }
    return vhead->next;
}

int main()
{
    int A[] = {1,2,3,3,4,4,5};
    int B[] = {1,1,1,2,3};
    int C[] = {1,2,3};
    int D[] = {1,1};
    printListNode(deleteDuplicates(buildListNode(A, 7)));
    printListNode(deleteDuplicates(buildListNode(B, 5)));
    printListNode(deleteDuplicates(buildListNode(C, 3)));
    printListNode(deleteDuplicates(buildListNode(D, 2)));
    return 0;
}
