
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

void flatten(TreeNode *root)
{
    if (root == NULL)
        return ;

    flatten(root->left);
    flatten(root->right);

    TreeNode *l = root->left;

    if (l == NULL)
        return ;
    while (l->right != NULL)
        l = l->right;

    l->right = root->right;
    root->right = root->left;
    root->left = NULL;

    return ;
}

int main()
{
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->left->left = new TreeNode(3);
    r->left->right = new TreeNode(4);
    r->right = new TreeNode(5);
    r->right->right = new TreeNode(6);

    flatten(r);

    TreeNode *t = r;
    for (;t != NULL; t = t->right)
        cout << t->val << endl;

    return 0;
}
