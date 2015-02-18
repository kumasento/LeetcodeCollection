
#include <iostream>
#include <string>
#include <vector>

#include "../leetcode.h"

using namespace std;

TreeNode *buildTree(vector<int>::iterator pb,
                    vector<int>::iterator pe,
                    vector<int>::iterator ib,
                    vector<int>::iterator ie)
{
    if (pe == pb || ie == ib)
        return NULL;
    int m = pe - pb;
    int n = ie - ib;

    int root = *pb;
    int sentry = 0;
    for (; sentry < n && *(ib+sentry) != root; sentry ++);

    TreeNode *node = new TreeNode(root);
    node->left = buildTree(pb+1, pb+1+sentry, ib, ib+sentry);
    node->right = buildTree(pb+1+sentry, pe, ib+sentry+1, ie);

    return node;
}   

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}


int main() {
    vector<int> inorder;
    inorder.push_back(1);
    inorder.push_back(0);
    inorder.push_back(2);

    vector<int> preorder;
    preorder.push_back(0);
    preorder.push_back(1);
    preorder.push_back(2);

    buildTree(preorder, inorder);

    return 0;
}
