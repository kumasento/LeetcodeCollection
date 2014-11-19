#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector< vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> node_queue; 
        vector< vector<int> > traversal_result;
        
        if (root == NULL) 
            return traversal_result;
        
        node_queue.push(root);
        int count = 1;
        int bound = count;
        int idx = 0;
        vector<int> tmp_result;
        while (!node_queue.empty()) {
            TreeNode *node_now = node_queue.front();
            node_queue.pop(); 

            tmp_result.push_back(node_now->val);
            if (node_now->left != NULL)     { node_queue.push(node_now->left);  count ++;} 
            if (node_now->right != NULL)    { node_queue.push(node_now->right); count ++;}
            idx ++;
            if (idx == bound) {
                bound = count;
                traversal_result.push_back(tmp_result);
                tmp_result.clear();
            }
        }

        return traversal_result;
    }   
};

int main() {
    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(18);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(20);

    Solution Sol;
    vector< vector<int> > res = Sol.levelOrder(root);

    int i, j;
    for (i = 0; i < res.size(); i++) {
        for (j = 0; j < res[i].size(); j++) 
            printf("%d,", res[i][j]);
        printf("\n");
    }
    return 0;
}
