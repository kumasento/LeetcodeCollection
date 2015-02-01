
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > cSum(vector<int> &cand, int target, int idx)
{
    vector< vector<int> > res;
    if (target == 0)
    {
        res.push_back(vector<int>());
        return res;
    }
    if (target < cand[idx])
        return res;
    for (int i = idx; i < cand.size(); i++)
    {
        if (target >= cand[i])
        {
            vector< vector<int> > tmpres = cSum(cand, target-cand[i], i);
            for (int j = 0; j < tmpres.size(); j++)
            {
                vector<int> tmp = tmpres[j];
                tmp.insert(tmp.begin(), cand[i]);
                res.push_back(tmp);
            }
        }
        else
            break;
    }
    return res;
}
vector< vector<int> > combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    return cSum(candidates, target, 0);
}

int main()
{
    vector<int> candidates(4);
    candidates[0] = 2;
    candidates[1] = 3;
    candidates[2] = 6;
    candidates[3] = 7;
    vector< vector<int> > res = combinationSum(candidates, 7);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
