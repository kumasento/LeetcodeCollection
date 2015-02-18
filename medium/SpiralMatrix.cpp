
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector< vector<int> > &matrix)
{

    vector<int> ans;
    int m = matrix.size();
    if (m <= 0) return ans;
    int n = matrix[0].size();
    if (n <= 0) return ans;

    int d = (n == 1) ? 1 : 0;
    int cnt = 0, maxcnt = m * n;
    int x = 0, y = 0;

    int x_low = 1, x_up = m-1;
    int y_low = 0, y_up = n-1;

    while (cnt < maxcnt)
    {
        cout << x << ' ' << y << ' ' << d << endl;
        ans.push_back(matrix[x][y]);

        // update direction
        switch (d)
        {
            case 0:
                y++;
                if (y == y_up)
                    y_up --, d ++;
                break;
            case 1:
                x++;
                if (x == x_up)
                    x_up --, d ++;
                break;
            case 2:
                y--;
                if (y == y_low)
                    y_low ++, d ++;
                break;
            case 3:
                x--;
                if (x == x_low)
                    x_low ++, d = 0;
        }

        cnt ++;
    }
    return ans;
}
int main()
{
    vector< vector<int> > matrix(2, vector<int>(1));
    matrix[0][0] = 3;
    matrix[1][0] = 2;

    vector<int> ans = spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
