
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode* swapPairs(ListNode *head)
{
    if (head == NULL)
        return NULL;

    ListNode *vhead = new ListNode(0);
    vhead->next = head;

    ListNode *p = vhead;
    ListNode *prev = head, *next = head->next;
    while (prev != NULL && next != NULL)
    {
        p->next = next;
        ListNode *tmp = next->next;
        next->next = prev;
        prev->next = tmp;

        p = prev;
        prev = tmp;
        next = (tmp == NULL) ? NULL : tmp->next;
    }

    return vhead->next;
}

int main()
{
    int A[] = {1,2,3};
    int B[] = {1,2,3,4};
    int C[] = {1};
    int D[] = {1,2,3,4,5};
    printListNode(swapPairs(buildListNode(A, 3)));
    printListNode(swapPairs(buildListNode(B, 4)));
    printListNode(swapPairs(buildListNode(C, 1)));
    printListNode(swapPairs(buildListNode(D, 5)));

    return 0;
}
