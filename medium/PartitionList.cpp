
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode *partition(ListNode *head, int x)
{
    if (head == NULL)
        return NULL;
    ListNode *p = head;

    ListNode *l1, *l2, *p1, *p2;
    l1 = new ListNode(0);
    l2 = new ListNode(0);

    p1 = l1, p2 = l2;
    while (p != NULL)
    {
        if (p->val < x)
            p1->next = p, p1 = p1->next;
        else
            p2->next = p, p2 = p2->next;
        p = p->next;
    }
    p1->next = l2->next;
    p2->next = NULL;
    return l1->next;
}

int main()
{
    int A[] = {1,4,3,2,5,2};
    int B[] = {2,1};
    int x = 3;

    printListNode(partition(buildListNode(A, 6), 3));
    printListNode(partition(buildListNode(A, 1), 3));
    printListNode(partition(buildListNode(A, 1), 1));
    printListNode(partition(buildListNode(B, 2), 2));

    return 0;
}
