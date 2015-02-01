#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector< vector<int> > dist(m+1, vector<int>(n+1, 0));

    // dist[i][j]:
    // if s1[i-1] == s2[j-1]:
    // 1. dist[i-1][j-1] -> do not need to change
    // 2. dist[i-1][j], dist[i][j-1] -> just choose a smaller one
    // else:
    // 1. dist[i-1][j-1] + 1 -> replace
    // 2. dist[i-1][j], dist[i][j-1] + 1 -> insert a character
    //

    for (int i = 0; i <= m; i++)
        dist[i][0] = i;
    for (int i = 0; i <= n; i++)
        dist[0][i] = i;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1])
                dist[i][j] = min(dist[i-1][j-1],
                                 min(dist[i-1][j], dist[i][j-1]) + 1);
            else
                dist[i][j] = min(dist[i-1][j-1] + 1,
                                 min(dist[i-1][j], dist[i][j-1]) + 1);
        }

    return dist[m][n];
}

int main() {
    cout << minDistance(string("word"), string("world")) << endl;
    cout << minDistance(string("a"), string("ab")) << endl;

    return 0;
}
