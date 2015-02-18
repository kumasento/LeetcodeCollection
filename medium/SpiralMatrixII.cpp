
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > generateMatrix(int n)
{
    vector< vector<int> > ans(n, vector<int>(n));
    if (n <= 0)
        return ans;

    int val = 1;
    int d = 0;
    int x = 0, y = 0;
    int x_min = 1, x_max = n-1;
    int y_min = 0, y_max = n-1;
    while (val <= n * n)
    {
        ans[x][y] = val++;
        switch (d)
        {
            case 0:
                y ++;
                if (y == y_max)
                    y_max--, d++;
                break;
            case 1:
                x ++;
                if (x == x_max)
                    x_max--, d++;
                break;
            case 2:
                y --;
                if (y == y_min)
                    y_min++, d++;
                break;
            case 3:
                x --;
                if (x == x_min)
                    x_min++, d = 0;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
