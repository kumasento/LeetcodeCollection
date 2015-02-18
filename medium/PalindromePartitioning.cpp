
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< vector<bool> > precalculate(string s)
{
    int n = s.length();
    vector< vector<bool> > dict(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        dict[i][i] = true;
    for (int len = 2; len <= n; len++)
        for (int i = 0; i+len-1 < n; i++)
        {
            int j = i + len - 1;

            dict[i][j] = (s[i] == s[j]);
            if (len > 2 && dict[i][j])
                dict[i][j] = dict[i+1][j-1];
        }

    return dict;
}

void helper(string s,
            vector< vector<bool> > &dict,
            int idx,
            vector< vector<string> > &ans)
{
    int n = s.length();

    if (idx == n)
        ans.push_back(vector<string>(0));
    for (int i = idx; i < n; i++)
        if (dict[idx][i])
        {
            //cout << s.substr(idx, i-idx+1) << endl;
            helper(s, dict, i+1, ans);

            int len = i - idx + 1;
            int j = ans.size() - 1;
            ans[j].insert(ans[j].begin(), s.substr(idx, len));
        }
}

vector< vector<string> > partition(string s)
{
    vector< vector<string> > ans;
    vector< vector<bool> > dict = precalculate(s);

    helper(s, dict, 0, ans);

    return ans;
}

int main()
{
    vector< vector<string> > ans = partition("abbab");

    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ((j == ans[i].size()-1) ? '\n' : ' ');

    return 0;
}
