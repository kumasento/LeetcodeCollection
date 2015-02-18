
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode* reorderList(ListNode *&head, int n)
{
    ListNode *ret, *tmp;

    if (n == 1)
    {
        ret = head->next;
        head->next = NULL;
    }
    else if (n == 2)
    {
        ret = head->next->next;
        head->next->next = NULL;
    }
    else
    {
        ListNode *tail = reorderList(head->next, n-2);
        ret = tail->next;
        tail->next = head->next;
        head->next = tail;
    }

    return ret;
}
void reorderList(ListNode *head)
{
    if (head == NULL)
        return ;
    int len = 0;
    ListNode *p = head;
    while (p != NULL)
        len ++, p = p->next;

    reorderList(head, len);
}

int main()
{
    int A[] = {1,2,3,4,5};
    ListNode * l = buildListNode(A, 5);
    reorderList(l);
    printListNode(l);
    return 0;
}
