
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > subsets(vector<int> &S)
{
    vector< vector<int> > res;

    int n = S.size();
    for (int i = 0; i <= (1<<n)-1; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
            if((i >> j) & 1)
                tmp.push_back(S[j]);
        sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
    }
    return res;
}

int main()
{

    return 0;
}
