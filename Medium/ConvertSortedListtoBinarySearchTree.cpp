

#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

TreeNode *sortedListToBST(ListNode *&head, int l, int r)
{
    if (l > r) return NULL;

    int mid = (l + r) / 2;
    TreeNode *rt = new TreeNode(0);

    rt->left  = (mid > l) ? sortedListToBST(head, l, mid-1) : NULL;
    rt->val = head->val;
    head = head->next;
    rt->right = (r > mid) ? sortedListToBST(head, 0, r-mid-1) : NULL;

    return rt;
}

TreeNode *sortedListToBST(ListNode *head)
{
    int len = 0;
    ListNode *p = head;
    while (p != NULL)
        len ++, p = p->next;

    return sortedListToBST(head, 0, len-1);
}

int main()
{
    int A[] = {1, 2, 3};

    ListNode *p = buildListNode(A, 3);

    TreeNode * rt = sortedListToBST(p);

    cout << rt->left->val << ' ' << rt->val << ' ' << rt->right->val << endl;

    return 0;
}
