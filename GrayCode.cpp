
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> grayCode(int n)
{
    int size = 1;
    for (int i = 1; i <= n; i++)
        size *= 2;

    vector<int> ans(size);
    if (size == 0)
        return ans;

    int vis[size];
    memset(vis, 0, sizeof(vis));

    // init
    ans[0] = 0;
    vis[0] = 1;

    for (int i = 1; i < size; i++)
        for (int j = 0; j < n; j++)
        {
            int last = ans[i-1];
            int tmp = 1<<j;
            tmp = last + ((last & tmp) ? -tmp : tmp);
            if (vis[tmp])
                continue;

            ans[i] = tmp;
            vis[tmp] = 1;
            break;
        }

    return ans;
}

int main()
{
    vector<int> ans = grayCode(4);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
