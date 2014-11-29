#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i, j;
        vector<int> ans(rowIndex+1);
        vector<int> tmp(rowIndex+1);
        
        ans[0] = tmp[0] = 1;
        for (i = 1; i <= rowIndex; i++) {
            for (j = 1; j <= i; j++) 
               tmp[j] = ans[j-1] + ans[j]; 
            tmp[i] = 1;
            swap(ans, tmp);
        }       

        return ans;
    }
};

int main() {

    Solution sol;
    for (int rowIndex = 0; rowIndex < 10; rowIndex ++) {
        vector<int> ans = sol.getRow(rowIndex);
        
        for (int i = 0; i <= rowIndex; i++) 
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
