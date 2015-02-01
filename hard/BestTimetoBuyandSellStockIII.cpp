#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();

    if (n <= 1) return 0;

    vector<int> f(n);
    vector<int> g(n);


     //f[i] records the maxProfit before i
    // g[i] records the maxProfit after i (including)

    for (int i = 1, min_price = prices[0]; i < n; i++) {
        min_price = min(min_price, prices[i]);
        f[i] = max(prices[i]-min_price, f[i-1]);
    }
    for (int i = n-2, max_price = prices[n-1]; i >= 0; i--) {
        max_price = max(max_price, prices[i]);
        g[i] = max(g[i+1], max_price-prices[i]);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < f[i] + g[i])
            max = f[i] + g[i];
    return max;
}

int main() {

    return 0;
}
