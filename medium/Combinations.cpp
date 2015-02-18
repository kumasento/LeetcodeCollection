
#include <iostream>
#include <vector>

using namespace std;

void helper(int n, int k, int start, vector<int> &num, vector< vector<int> > &ans)
{
    if (num.size() == k)
    {
        ans.push_back(num);
        return ;
    }
    num.push_back(0);
    int tail = num.size() - 1;
    for (int i = start; i <= n; i++)
    {
        num[tail] = i;
        helper(n, k, i+1, num, ans);
    }
    num.erase(num.end()-1);
}

vector< vector<int> > combine(int n, int k)
{
    vector< vector<int> > ans;
    vector<int> num;
    helper(n, k, 1, num, ans);

    return ans;
}

int main()
{
    vector< vector<int> > ans = combine(4,3);

    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ((j==ans[i].size()-1) ? '\n' : ' ');
    cout << "Total: " << ans.size() << endl;

    return 0;
}
