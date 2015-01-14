#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int minPathSum(vector< vector<int> > &grid) {
    // checking ...
    int m = grid.size();    if (m <= 0) return -1;
    int n = grid[0].size(); if (n <= 0) return -1;

    vector< vector<int> > Min(m, vector<int>(n));

    Min[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) 
        Min[i][0] = Min[i-1][0] + grid[i][0];

    for (int j = 1; j < n; j++)
        Min[0][j] = Min[0][j-1] + grid[0][j];

    // from left to right
    // from up to bottom
    for (int i = 1; i < m; i++) 
        for (int j = 1; j < n; j++) 
            Min[i][j] = min(Min[i-1][j], Min[i][j-1]) + grid[i][j];

    return Min[m-1][n-1];
}

int main() {
    vector< vector<int> > grid(2, vector<int>(2));
    grid[0][0] = 0;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 0;

    cout << minPathSum(grid) << endl;

    return 0;
}
