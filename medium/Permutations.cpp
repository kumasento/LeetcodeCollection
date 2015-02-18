
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector< vector<int> > permute(vector<int> &num)
{
    vector< vector<int> > ans;
    int n = num.size();
    if (!n)
        return ans;

    vector<int> p(n, 0);
    while (true)
    {
        // use p first
        vector<int> res;
        vector<int> mask(n, 0);

        for (int i = 0; i < n; i++)
        {
            int cnt = 0, j;
            for (j = 0; j < n && cnt <= p[i]; j++)
                if (!mask[j])
                    cnt ++;
            j --;
            res.push_back(num[j]);
            mask[j] = 1;
        }
        ans.push_back(res);

        // update p
        bool ok = false;
        for (int i = n-2; i >= 0; i--)
        {
            int ub = n-i-1;
            if (p[i] >= ub)
            {
                p[i] = 0;
                continue;
            }
            p[i] ++;
            ok = true;
            break;
        }

        if (!ok) break;
    }

    return ans;
}

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(8);
    num.push_back(9);

    vector<vector<int> > ans = permute(num);

    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ' << ((j==ans[i].size()-1) ? '\n' : ' ');

    cout << "Total: " << ans.size() << endl;
    return 0;
}
