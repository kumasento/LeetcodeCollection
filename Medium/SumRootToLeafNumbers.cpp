
#include <iostream>
#include <vector>
#include "../leetcode.h"

using namespace std;

void iterateSum(TreeNode *root, int num, int &sum)
{
    num = num * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
    {
        sum += num;
        return;
    }

    if (root->left != NULL)
        iterateSum(root->left, num, sum);
    if (root->right != NULL)
        iterateSum(root->right, num, sum);

    return ;
}

int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    iterateSum(root, 0, sum);

    return sum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << sumNumbers(root) << endl;

    return 0;
}
