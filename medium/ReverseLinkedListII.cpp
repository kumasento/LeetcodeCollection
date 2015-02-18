
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#include "../leetcode.h"

using namespace std;

ListNode* reverseBetween(ListNode *head, int m, int n)
{
    if (head == NULL) return NULL;

    // at least m <= n+1
    int cnt = 1;
    ListNode *rhead = NULL, *rtail = NULL; // rhead and rtail mean reversed-
    ListNode *p = head;
    ListNode *prev = NULL;
    while (p != NULL)
    {
        if (cnt == m-1)
            rhead = p; // if m != 1; or rhead = NULL;
        if (cnt == m)
            rtail = p; // the first is the last
        ListNode *tmp = p->next;
        if (cnt >= m && cnt <= n)
        {
            p->next = prev;
            prev = p;
        }
        if (cnt == n)
        {
            rtail->next = tmp;
            if (rhead != NULL)
                rhead->next = prev;
            else
                head = prev;
        }
        p = tmp; // move to the next;
        cnt ++;
    }

    return head;
}

int main()
{
    int A[] = {1,2,3,4,5};
    ListNode *p = buildListNode(A, 5);
    ListNode *ans = reverseBetween(p, 1, 2);

    while (ans != NULL)
    {
        cout << ans->val << ' ';
        ans = ans->next;
    }

    return 0;
}
