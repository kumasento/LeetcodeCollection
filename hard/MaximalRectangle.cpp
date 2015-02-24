
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int maximalRectangle(vector< vector<char> > &matrix)
{
    int m = matrix.size();
    if (m <= 0)
        return 0;
    int n = matrix[0].size();
    if (n <= 0)
        return 0;
    int max_area = 0;
    vector<int> height(n+1, 0);
    height[n] = 0;
    for (int i = 0; i < m; i++)
    {
        stack<int> s;
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == '1')
                height[j] = (i != 0 && matrix[i-1][j] == '1')
                            ? height[j] + 1
                            : 1;
            else
                height[j] = 0;
        int idx = 0;
        while (idx <= n)
        {
            if (s.empty() || height[s.top()] <= height[idx])
                s.push(idx), idx ++;
            else
            {
                int left_most = s.top();
                s.pop();
                int width_to_left = idx;
                if (!s.empty())
                    width_to_left = idx - s.top() - 1;
                max_area = max(max_area, width_to_left * height[left_most]);
            }
        }
    }
    return max_area;
}

int main()
{
    vector< vector<char> > matrix(1, vector<char>(1, '1'));

    cout << maximalRectangle(matrix) << endl;

    return 0;
}
