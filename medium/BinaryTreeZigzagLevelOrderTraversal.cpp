
#include <iostream>
#include <stack>
#include <vector>

#include "../leetcode.h"

using namespace std;

vector< vector<int> > zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int> > ans;

    if (root == NULL)
        return ans;

    vector<int> res;
    res.push_back(root->val);
    ans.push_back(res);

    stack<TreeNode *> s;
    s.push(root);

    int l = 0;
    while (!s.empty())
    {
        stack<TreeNode *> ns;
        res = vector<int> (0);

        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();

            if (!(l%2))
            {
                if (t->right != NULL)
                {
                    res.push_back(t->right->val);
                    ns.push(t->right);
                }
                if (t->left != NULL)
                {
                    res.push_back(t->left->val);
                    ns.push(t->left);
                }
            }
            else
            {
                if (t->left != NULL)
                {
                    res.push_back(t->left->val);
                    ns.push(t->left);
                }
                if (t->right != NULL)
                {
                    res.push_back(t->right->val);
                    ns.push(t->right);
                }
            }
        }
        if (res.size() != 0)
            ans.push_back(res);
        l ++;
        s = ns;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    vector< vector<int> > ans = zigzagLevelOrder(root);

    cout << "end" << endl;

    print2DimArray<int> (ans);
    return 0;
}
