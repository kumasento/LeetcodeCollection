#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CMP(int x, int y) { return (x == 0 || x > y) ? y : x; }

struct MaxInfo
{
    int x, y, h, w;

    MaxInfo() { x=y=h=w=0; }
    MaxInfo(int x, int y, int h, int w)
        : x(x), y(y), h(h), w(w)
    {}

    int S() { return h * w; }
};

int maximalRectangle(vector< vector<char> > &matrix)
{
    int m = matrix.size();
    if (m <= 0) return 0;
    int n = matrix[0].size();
    if (n <= 0) return 0;

    vector< vector<MaxInfo> > dp(m, vector<MaxInfo>(n));

    dp[0][0] = (matrix[0][0] == '1') ? MaxInfo(1,1,1,1) : MaxInfo(0,0,0,0);

    for (int i = 1; i < n; i++)
        dp[0][i] =
            (matrix[0][i] == '1')
            ? MaxInfo(1, dp[0][i-1].y+1, 1, dp[0][i-1].w+1)
            : MaxInfo(0, 0, 0, 0);
    for (int i = 1; i < m; i++)
        dp[i][0] =
            (matrix[i][0] == '1')
            ? MaxInfo(dp[i-1][0].x+1, 1, dp[i-1][0].h+1, 1)
            : MaxInfo(0, 0, 0, 0);

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == '0')
                dp[i][j] = MaxInfo(0, 0, 0, 0);
            else
            {
                int x = dp[i-1][j].x + 1;
                int y = dp[i][j-1].y + 1;
                dp[i][j] = MaxInfo(x,y,1,1); //init
                if (matrix[i][j-1] == '1')
                {
                    int h = min(dp[i][j-1].h, x);
                    int w = dp[i][j-1].w+1;
                    dp[i][j] = (h*w > dp[i][j].S()) ? MaxInfo(x, y, h, w) : dp[i][j];
                }
                if (matrix[i-1][j] == '1')
                {
                    int h = dp[i-1][j].h+1;
                    int w = min(dp[i-1][j].w, y);
                    dp[i][j] = (h*w > dp[i][j].S()) ? MaxInfo(x, y, h, w) : dp[i][j];
                }
                if (matrix[i-1][j] == '1' && matrix[i][j-1] == '1' && matrix[i-1][j-1] == '1')
                {
                    int h = min(dp[i-1][j-1].h+1, x);
                    int w = min(dp[i-1][j-1].w+1, y);
                    dp[i][j] = (h*w > dp[i][j].S()) ? MaxInfo(x, y, h, w) : dp[i][j];
                }
            }

    int maxres = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            maxres = max(maxres, dp[i][j].S());

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf("dp[%d][%d]: %d %d %d %d => %d\n",
                    i,
                    j,
                    dp[i][j].x,
                    dp[i][j].y,
                    dp[i][j].h,
                    dp[i][j].w,
                    dp[i][j].S());

    return maxres;
}

int main()
{
    vector< vector<char> > matrix(3, vector<char>(4));
    matrix[0][0] = '1';
    matrix[0][1] = '1';
    matrix[0][2] = '0';
    matrix[0][3] = '1';

    matrix[1][0] = '1';
    matrix[1][1] = '1';
    matrix[1][2] = '0';
    matrix[1][3] = '1';

    matrix[2][0] = '1';
    matrix[2][1] = '1';
    matrix[2][2] = '1';
    matrix[2][3] = '1';

    cout << maximalRectangle(matrix) << endl;
    return 0;
}
