
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector< vector<int> > enumerate(vector< pair<int, int> > items,
                                int idx)
{
    if (idx == items.size())
        return vector< vector<int> >(1);

    vector< vector<int> > ans;

    vector< vector<int> > res = enumerate(items, idx+1);
    for (int i = 0; i <= items[idx].second; i++)
        for (int j = 0; j < res.size(); j++)
        {
            vector<int> tmp = res[j];
            for (int k = 0; k < i; k++)
                tmp.insert(tmp.begin(), items[idx].first);
            ans.push_back(tmp);
        }
    return ans;
}
vector< vector<int> > subsetsWithDup(vector<int> &S)
{
    sort(S.begin(), S.end());

    vector< pair<int, int> > items;
    items.push_back(pair<int, int>(S[0], 1));
    for (int i = 1; i < S.size(); i++)
        if (S[i] == S[i-1])
            items.back().second ++;
        else
            items.push_back(pair<int, int>(S[i], 1));

    vector< vector<int> > ans = enumerate(items, 0);
    return ans;
}

int main()
{
    int A[] = {5,4,5,4,3,3,1,1,1,2};
    vector<int> S(A, A+10);
    vector< vector<int> > ans = subsetsWithDup(S);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
