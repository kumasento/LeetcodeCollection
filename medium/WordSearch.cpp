
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool dfs(vector< vector<char> > &board, int x, int y, string word, int i)
{
    if (i == word.length()-1)
        return true;
    int m = board.size();
    int n = board[0].size();

    board[x][y] = '#';
    for (int d = -1; d <= 1; d += 2)
        for (int k = 0; k <= 1; k++)
        {
            int tx = x + d * k;
            int ty = y + d * (1-k);
            if (tx >= 0 && tx < m && ty >= 0 && ty < n)
                if (board[tx][ty] == word[i+1])
                {
                    bool ok = dfs(board, tx, ty, word, i+1);
                    if (ok)
                    {
                        board[x][y] = word[i];
                        return ok;
                    }
                }
        }
    board[x][y] = word[i];
    return false;
}
bool exist(vector< vector<char> > &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                return true;
        }
    return false;
}

int main()
{
    vector< vector<char> > board(5, vector<char>(4));
    board[0][0] = 'a';
    board[0][1] = 'a';
    board[0][2] = 'a';
    board[0][3] = 'a';

    board[1][0] = 'a';
    board[1][1] = 'a';
    board[1][2] = 'a';
    board[1][3] = 'a';

    board[2][0] = 'a';
    board[2][1] = 'a';
    board[2][2] = 'a';
    board[2][3] = 'a';

    board[3][0] = 'a';
    board[3][1] = 'a';
    board[3][2] = 'a';
    board[3][3] = 'a';

    board[4][0] = 'a';
    board[4][1] = 'a';
    board[4][2] = 'a';
    board[4][3] = 'b';
    string word = "aaaaaaaaaaaaaaaaaaaa";

    cout << exist(board, word) << endl;

    return 0;
}
