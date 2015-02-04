#ifndef _LEET_CODE_H_
#define _LEET_CODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

TreeNode * TreeExample() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    return root;
}

ListNode *buildListNode(int A[], int n)
{
    if (n <= 0)
        return NULL;
    ListNode *p = new ListNode(A[0]);
    ListNode *tmp = p;
    for (int i = 1; i < n; i++)
    {
        tmp->next = new ListNode(A[i]);
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return p;
}

void printListNode(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

#endif
