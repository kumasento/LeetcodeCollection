
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;

TreeNode *generate(vector<int> &num, int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;
    TreeNode *rt = new TreeNode(num[mid]);
    rt->left = generate(num, l, mid-1);
    rt->right = generate(num, mid+1, r);

    return rt;
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
    return generate(num, 0, num.size()-1);
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    vector<int> num(A, A+5);

    sortedArrayToBST(num);

    return 0;
}
