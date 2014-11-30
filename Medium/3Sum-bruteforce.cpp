#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector< vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int len = num.size();

        vector< vector<int> > ans;
        for (int i = 0; i < len; i++) 
            for (int j = i + 1; j < len; j++)
                for (int k = j + 1; k < len; k++) 
                    if (num[i] + num[j] + num[k] == 0) {
                        vector<int> tmp(3);

                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[k];
                        
                        int t;
                        for (t = 0; t < ans.size(); t++)
                            if (tmp[0] == ans[t][0] &&
                                tmp[1] == ans[t][1] &&
                                tmp[2] == ans[t][2])
                                    break;
                        if (t == ans.size()) ans.push_back(tmp);
                    }

        return ans;
    }
};

int main() {
    int S[] = {-1, 0, 1, 2, -1, -4};
    vector<int> vS(S, S + sizeof(S)/sizeof(int));

    Solution sol;
    vector< vector<int> > ans = sol.threeSum(vS);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
