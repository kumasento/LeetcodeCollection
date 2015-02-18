
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > cSum2(vector<int> &num, int target, int idx)
{
    vector< vector<int> > res;
    if (target == 0) // success
        return vector< vector<int> > (1);
    if (target < 0) // failed
        return vector< vector<int> > (0);
    for (int i = idx; i < num.size(); i++)
    {
        vector< vector<int> > tmpres = cSum2(num, target-num[i], i+1);
        for (int j = 0; j < tmpres.size(); j++)
        {
            vector<int> tmp = tmpres[j];
            tmp.insert(tmp.begin(), num[i]);
            res.push_back(tmp);
        }
        while (i < num.size() - 1 && num[i] == num[i+1]) i++;
    }
    return res;
}
vector< vector<int> > combinationSum2(vector<int> &num, int target)
{
    sort(num.begin(), num.end());
    return cSum2(num, target, 0);
}

int main()
{
    vector<int> num(2);
    num[0] = 1;
    num[1] = 1;
    vector< vector<int> > res = combinationSum2(num, 1);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
