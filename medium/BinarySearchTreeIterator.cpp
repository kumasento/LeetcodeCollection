
#include <iostream>
#include <stack>
#include <string>

#include "../leetcode.h"

using namespace std;

class BSTIterator
{
    public:
        stack<TreeNode *> s;
        BSTIterator(TreeNode *root)
        {
            pushLeft(root);
        }
        void pushLeft(TreeNode *root)
        {
            TreeNode *tmp = root;
            while (tmp != NULL)
                s.push(tmp), tmp = tmp->left;
        }
        bool hasNext()
        {
            return !s.empty();
        }
        int next()
        {
            TreeNode *t = s.top();
            s.pop();

            if (t->right != NULL)
                pushLeft(t->right);

            return t->val;
        }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    BSTIterator i(root);
    while (i.hasNext())
        cout << i.next() << ' ';
    cout << endl;

    return 0;
}
