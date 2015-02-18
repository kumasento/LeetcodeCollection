
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode *rotateRight(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;
    int cnt = 0;

    int len = 0;
    ListNode *p = head;
    while (p != NULL) p = p->next, len ++;
    n = n % len;

    ListNode *vhead = new ListNode(0);
    vhead->next = head;

    ListNode *rot = vhead;
    while (cnt < len-n)
        cnt ++, rot = rot->next;

    if (rot == vhead)
        return vhead->next;
    if (rot->next == NULL) // means it's the end now;
        return vhead->next;
    vhead->next = rot->next;
    rot->next = NULL;
    rot = vhead->next;
    while (rot->next != NULL)
        rot = rot->next;

    rot->next = head;
    return vhead->next;
}

int main()
{
    int A[] = {1,2,3,4,5};
    for (int i = 0; i < 20; i++)
        printListNode(rotateRight(buildListNode(A, 5),i));

    return 0;
}
