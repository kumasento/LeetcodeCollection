#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        int i, j;
        vector< vector<int> > ans(numRows);
        
        if (numRows <= 0) 
            return ans;
        ans[0].push_back(1); //--initialization
        for (i = 1; i < numRows; i++) {    
            ans[i].push_back(1);
            
            for (j = 1; j < i; j++) 
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);

            ans[i].push_back(1);
        }

        return ans;
    }
};

int main() {

    int numRows = 20;
    Solution sol;

    vector< vector<int> > ans = sol.generate(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) 
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
