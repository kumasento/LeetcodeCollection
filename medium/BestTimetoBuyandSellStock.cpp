#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();

    if (n <= 1) return 0;

    vector<int> f(n);

    // f[i] records the smallest number before i
    f[0] = prices[0];
    for (int i = 1; i < n; i++)
        f[i] = (f[i-1] < prices[i]) ? f[i-1] : prices[i];

    int max = 0;
    for (int i = 0; i < n; i++)
        max = (max > prices[i]-f[i]) ? max : prices[i]-f[i];

    return max;
}

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);

    cout << maxProfit(prices) << endl;

    return 0;
}
