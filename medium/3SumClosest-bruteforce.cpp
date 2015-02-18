#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int min = num[0] + num[1] + num[2];
        
        for (int i = 0; i < num.size(); i++)
            for (int j = i+1; j < num.size(); j++)
                for (int k = j+1; k < num.size(); k++) {
                    int ans = num[i] + num[j] + num[k];
                    int dis = abs(ans - min);
                    if (dis < abs(min-target)) 
                        min = ans;
                }
        
        return min;
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
