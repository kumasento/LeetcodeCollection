
#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include "../leetcode.h"

using namespace std;

void marker(vector<vector<char> > &board, int x, int y)
{
    int m = board.size();
    int n = board[0].size();

    queue< pair<int, int> > q;
    q.push(pair<int, int>(x, y));
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        x = p.first;
        y = p.second;

        if (board[x][y] != 'O')
            continue;

        board[x][y] = '#';
        if (x-1 >= 0 && board[x-1][y] == 'O') q.push(pair<int, int>(x-1, y));
        if (y-1 >= 0 && board[x][y-1] == 'O') q.push(pair<int, int>(x, y-1));
        if (x+1 <  m && board[x+1][y] == 'O') q.push(pair<int, int>(x+1, y));
        if (y+1 <  n && board[x][y+1] == 'O') q.push(pair<int, int>(x, y+1));
    }
}

void solve(vector<vector<char> > &board)
{
    int m = board.size();
    if (m <= 0)
        return ;
    int n = board[0].size();
    if (n <= 0)
        return ;
    // marker
    for (int i = 0; i < m; i++)
        if (board[i][0] == 'O')
            marker(board, i, 0);
    for (int i = 0; i < m; i++)
        if (board[i][n-1] == 'O')
            marker(board, i, n-1);
    for (int i = 0; i < n; i++)
        if (board[0][i] == 'O')
            marker(board, 0, i);
    for (int i = 0; i < n; i++)
        if (board[m-1][i] == 'O')
            marker(board, m-1, i);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == '#')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
}

int main()
{
    int m = 500;
    int n = 500;
    vector< vector<char> > board(m, vector<char>(n, 'X'));

    for (int i = 0; i < m; i++)
    {
        if (!(i%2))
            for (int j = 0; j < n; j++)
                board[i][j] = 'O';
        else if ((i/2) % 2)
            board[i][0] = 'O';
        else
            board[i][n-1] = 'O';
    }

    solve(board);

    print2DimArray(board);

    return 0;
}
