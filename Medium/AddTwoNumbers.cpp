
#include <iostream>
#include <vector>
#include <stack>

#include "../leetcode.h"

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode* l2)
{
    if (l1 == NULL || l2 == NULL)
        return NULL;

    ListNode *root = new ListNode(0);
    ListNode *tmp = root;
    int g = 0;
    while (g != 0 || l1 != NULL || l2 != NULL)
    {
        int p1 = 0, p2 = 0;
        if (l1 != NULL) { p1 = l1->val; l1 = l1->next; }
        if (l2 != NULL) { p2 = l2->val; l2 = l2->next; }
        int sum = p1 + p2 + g;
        g = sum / 10;
        sum = sum % 10;

        tmp->next = new ListNode(sum);
        tmp = tmp->next;
    }

    return root->next;
}

int main()
{
    ListNode *l1, *l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *ans = addTwoNumbers(l1, l2);
    while (ans != NULL)
    {
        cout << ans->val << ' ';
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
