#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int min = INT_MAX, ans;
        for (int i = 0; i < num.size(); i++) {
            int j = i + 1;
            int k = num.size() - 1;

            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                int dis = sum - target;
                if (dis == 0) { min = 0; ans = sum; break; } 
                // -- here is the trick:
                // -- if sum is too small, then add j
                // -- else sub k
                else if (dis < 0) {
                    if (-dis < min) { min = -dis; ans = sum; }
                    j ++;
                }
                else {
                    if (dis < min) { min = dis; ans = sum; }
                    k --;
                }
            }
            while(i<num.size()-1 && num[i] == num[i+1]) i++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> S;
    S.push_back(-1);
    S.push_back(2);
    S.push_back(1);
    S.push_back(-4);

    int target = 1;

    cout << sol.threeSumClosest(S, target);

    return 0;
}
