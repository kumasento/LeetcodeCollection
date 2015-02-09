
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string getPermutation(int n, int k)
{
    k --;
    int nn = 1;
    for (int i = 1; i < n; i++)
        nn *= i;

    int vis[n+1];
    memset(vis, 0, sizeof(vis));

    int l = n-1;
    string ans;
    while (l > 0)
    {
        int idx = k / nn;
        k = k % nn;
        int cnt = 0, i;
        for (i = 1; i <= n && cnt <= idx; i++)
        {
            while (vis[i]) i++;
            cnt ++;
        }
        i --;
        ans.push_back(i+'0');
        vis[i] = 1;

        nn /= l;
        l --;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ans.push_back(i+'0');

    return ans;
}

int main()
{
    cout << getPermutation(3, 1) << endl;
    cout << getPermutation(3, 2) << endl;
    cout << getPermutation(3, 3) << endl;
    cout << getPermutation(3, 4) << endl;
    cout << getPermutation(3, 5) << endl;

    return 0;
}
