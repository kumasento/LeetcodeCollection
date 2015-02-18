#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    // f[m][n] = f[m-1][n] + f[m][n-1]
    vector< vector<int> > f(m, vector<int>(n));

    for (int i = 0; i < n; i++)
        f[0][i] = 1;
    for (int j = 1; j < m; j++)
        f[j][0] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            f[i][j] = f[i-1][j] + f[i][j-1];

    return f[m-1][n-1];
}

int main() {
    cout << uniquePaths(2, 2) << endl; 
    cout << uniquePaths(3, 3) << endl; 

    return 0;
}
