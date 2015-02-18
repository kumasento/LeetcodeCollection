
#include <iostream>
#include <vector>
#include "../leetcode.h"

using namespace std;

void iterate(TreeNode *root, int num, int sum, vector<int> &v, vector<vector<int> > &ans)
{
    if (root == NULL)
        return ;
    num += root->val;
    v.push_back(root->val);

    if (root->left == NULL && root->right == NULL)
        if (num == sum)
            ans.push_back(v);
    if (root->left != NULL)
        iterate(root->left, num, sum, v, ans);
    if (root->right != NULL)
        iterate(root->right, num, sum, v, ans);

    v.erase(v.end()-1);
}

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
    vector<int> v;
    vector<vector<int> > ans;
    iterate(root, 0, sum, v, ans);
    return ans;
}

int main()
{
    TreeNode *r = new TreeNode(5);
    r->left = new TreeNode(4);
    r->right = new TreeNode(8);
    r->left->left = new TreeNode(11);
    r->left->left->left = new TreeNode(7);
    r->left->left->right = new TreeNode(2);
    r->right->left = new TreeNode(13);
    r->right->right = new TreeNode(4);
    r->right->right->left = new TreeNode(5);
    r->right->right->right = new TreeNode(1);

    int sum = 22;
    vector<vector<int> > ans = pathSum(r, sum);
    print2DimArray(ans);

    return 0;
}
