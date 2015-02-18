#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector< vector<int> > &obstacleGrid) {
    // f[i][j] = f[i-1][j] + f[i][j-1]
    // if (i, j) is a obstacle: f[i][j] = 0
    //
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    int f[m][n];

    f[0][0] = 1 - obstacleGrid[0][0];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) 
                continue;

            f[i][j] = 0;
            if (obstacleGrid[i][j]) 
                continue;
            if (i != 0) 
                f[i][j] += f[i-1][j] * (1-obstacleGrid[i-1][j]);
            if (j != 0) 
                f[i][j] += f[i][j-1] * (1-obstacleGrid[i][j-1]);

            //cout << i << ' ' << j << ' ' << f[i][j] << endl;
        }
    
    return f[m-1][n-1];
}

int main() {

    vector< vector<int> > grid(1, vector<int>(2));

    grid[0][0] = 0;
    grid[0][1] = 1;

    cout << uniquePathsWithObstacles(grid) << endl;

    return 0;
}
