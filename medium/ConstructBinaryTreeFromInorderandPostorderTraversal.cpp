#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "../leetcode.h"

using namespace std;

TreeNode *buildTree(vector<int>::iterator ibegin, 
                    vector<int>::iterator iend, 
                    vector<int>::iterator pbegin,
                    vector<int>::iterator pend) 
{
    if (ibegin == iend || pbegin == pend)
        return NULL;

    int root = *(pend - 1);

    int i = 0;
    int m = iend - ibegin;
    int n = pend - pbegin;
    for (; i < m && *(ibegin+i) != root; i++);
    
    TreeNode *node = new TreeNode(root);
    node->left = buildTree(ibegin, ibegin+i, pbegin, pbegin+i);
    node->right = buildTree(ibegin+i+1, iend, pbegin+i, pend-1);

    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
    return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}


int main() {
    vector<int> inorder, postorder;
    inorder.push_back(1);
    inorder.push_back(0);
    inorder.push_back(2);

    postorder.push_back(1);
    postorder.push_back(2);
    postorder.push_back(0);

    buildTree(inorder, postorder);

    return 0;
}
