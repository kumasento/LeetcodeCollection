#include <iostream>
#include <string>
#include <vector>

#include "tree.h"

using namespace std;

class Solution {
public:
    
    void levelOrder(TreeNode *root, vector< vector<int> >&ans, int level) {
        if (root == NULL) return ;
        
        vector<int> tmp; tmp.push_back(root->val);
        if (ans.size() == level) 
            ans.push_back(tmp);
        else
            ans[level].push_back(root->val);
        
        levelOrder(root->left, ans, level + 1);
        levelOrder(root->right, ans, level + 1);
    }

    vector< vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector<int> > ans;
        
        levelOrder(root, ans, 0);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    
    TreeNode *root = TreeExample();
    
    Solution sol;
    vector< vector<int> > ans = sol.levelOrderBottom(root);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) 
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
