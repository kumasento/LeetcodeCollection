#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int numDistinct(string S, string T) {
    int m = S.length();
    int n = T.length();

    vector< vector<int> > f(m+1, vector<int>(n+1, 0));
    for (int i = 0; i <= n; i++)
        f[0][i] = 1;

    for (int j = 0; j <= n; j++)
        for (int i = 0; i <= m; i ++) 
            f[i][j] = f[i][j-1] 
                    + (T[i-1] == S[j-1]) ? f[i-1][j-1] : 0;
    
    return f[m][n];
}

int main() {

    return 0;
}
