
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../leetcode.h"

using namespace std;

bool isValidBST(TreeNode *root, long long l, long long u)
{
    if (root == NULL)
        return true;

    long long val = root->val;
    if (val <= l || val >= u)
        return false;

    bool l_res = isValidBST(root->left, l, val);
    bool r_res = isValidBST(root->right, val, u);

    return l_res && r_res;
}

bool isValidBST(TreeNode *root)
{
    return isValidBST(root, (long long)INT_MIN-1, (long long)INT_MAX+1);
}

int main()
{
    TreeNode *root = new TreeNode(2147483647);

    cout << isValidBST(root) << endl;

    return 0;
}

