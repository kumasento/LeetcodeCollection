#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 0) return 0;
        vector<int> f(prices.size());
        for (int i=prices.size()-1; i>=0; i--) {
            if (i != prices.size() - 1)
                f[i] = (prices[i] > f[i+1]) ? prices[i] : f[i+1];
            else
                f[i] = prices[i];
        }
        
        int max = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
            if (f[i] - prices[i] > max)
                max = f[i] - prices[i];

        return max;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    prices.push_back(0);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(1);

    cout << sol.maxProfit(prices);
    
    return 0;
}
