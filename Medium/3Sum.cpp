#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector< vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        // -- 1st pass: sort array
        sort(num.begin(), num.end());

        // -- 2nd pass: 
        vector< vector<int> > ans;
        for (int i = 0; i < len - 2; i++) {
            if (i == 0 || num[i] > num[i-1]) {
                int j = i + 1;
                int k = len - 1;

                while (j < k) {
                    if (num[j] + num[k] == -num[i]) {
                        vector<int> tmp(3);
                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[k];
                        ans.push_back(tmp);
                        k --;
                        j ++;
                        while (k > j && num[k] == num[k+1]) k--;
                        while (k > j && num[j] == num[j-1]) j++;
                    }
                    else if (num[j] + num[k] > -num[i])
                        k--;
                    else 
                        j++;
                }
            }
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
