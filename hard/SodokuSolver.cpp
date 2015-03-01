
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool backtrack(vector< vector<char> > &board, int x, int y,
        int filled[3][3], int used[10]) {
    int cnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (filled[i][j])
                cnt ++;
    if (cnt == 9) {
        int num_board[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                num_board[i][j] = board[x+i][y+j]-'0';
        cout << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << num_board[i][j];
            cout << endl;
        }
        int sum = num_board[0][0]+num_board[1][0]+num_board[2][0];
        if (num_board[0][0]+num_board[0][1]+num_board[0][2] == sum &&
            num_board[1][0]+num_board[1][1]+num_board[1][2] == sum &&
            num_board[2][0]+num_board[2][1]+num_board[2][2] == sum &&
            num_board[0][1]+num_board[1][1]+num_board[2][1] == sum &&
            num_board[0][2]+num_board[1][2]+num_board[2][2] == sum &&
            num_board[0][0]+num_board[1][1]+num_board[2][2] == sum &&
            num_board[2][0]+num_board[1][1]+num_board[0][2] == sum) {
            return true;
        }
        return false;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (filled[i][j])
                continue;
            for (int num = 1; num <= 9; num++) {
                if (!used[num]) {
                    board[x+i][y+j] = num+'0';
                    filled[i][j] = 1;
                    used[num] = 1;
                    if (backtrack(board, x, y, filled, used))
                        return true;
                    filled[i][j] = 0;
                    used[num] = 0;
                }
            }
        }
    return false;
}

void solveSudoku(vector< vector<char> > &board) {
    int m = board.size();
    if (m != 9) return ;
    int n = board[0].size();
    if (n != 9) return ;

    int filled[3][3], used[10];
    for (int x = 0; x < 9; x+=9)
        for (int y = 0; y < 9; y+=9) {
            memset(filled, 0, sizeof(filled));
            memset(used, 0, sizeof(used));
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    filled[i][j] = (board[x+i][y+j] != '.');
                    used[board[x+i][y+j]-'0'] = 1;
                }
            backtrack(board, x, y, filled, used);
        }
}

int main() {
    freopen("SodokuSolve.in", "r", stdin);
    vector< vector<char> > board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++) {
        string str; cin>>str;
        for (int j = 0; j < 9; j++)
            board[i][j] = str[j];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << endl;
    }

    solveSudoku(board);
    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << endl;
    }
    return 0;
}
