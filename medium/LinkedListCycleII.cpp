
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *fast, *slow;
    slow = head->next;
    fast = head->next->next;

    int l1 = 0, l2 = 0;
    while (fast != NULL)
    {
        if (fast == slow) break;
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL) break;
        fast = fast->next;
    }
    if (fast == NULL)
        return NULL;
    ListNode *p = head;
    while (p != slow)
        p = p->next, slow = slow->next;
    return slow;
}

int main()
{

    return 0;
}
