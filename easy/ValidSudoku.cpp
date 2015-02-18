#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector< vector<char> > &board) {
        if (board.size() != 9 || board[0].size() != 9) return false;

        // -- pass 1: check rows:
        for (int i = 0; i < board.size(); i++) {
            vector<int> mask(10, 0);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                int idx = board[i][j] - '0';
                if (mask[idx] == 1) return false;
                mask[idx] = 1;
            }
        }

        // -- pass 2: check columns:
        for (int j = 0; j < board[0].size(); j++) {
            vector<int> mask(10, 0);
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == '.') continue;
                int idx = board[i][j] - '0';
                if (mask[idx] == 1) return false;
                mask[idx] = 1;
            }
        }

        // -- pass 3: check block
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<int> mask(10, 0);
                for (int kx = i * 3; kx < (i + 1) * 3; kx ++)
                    for (int ky = j * 3; ky < (j + 1) * 3; ky ++) {
                        if (board[kx][ky] == '.') continue;
                        int idx = board[kx][ky] - '0';
                        if (mask[idx] == 1) return false;
                        mask[idx] = 1;
                    }
            }
        }

        return true;
    }
}
