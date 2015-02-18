
#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector< vector<int> > &matrix) 
{
    // set the row i and col j to be zeroes
    // but how could we make sure that some elements in this 
    // row or col are not zero afterwards?
    //
    // just set them to be minus, and swipe it again
    // however, what about some elements are naturally zeroes?
    //
    // just store the values in the first row and first col
    //

    int m = matrix.size();
    int n = matrix[0].size();

    bool row = false, col = false;

    for (int k = 0; k < m; k++)
        if (!matrix[k][0])
            col = true;
    for (int k = 0; k < n; k++)
        if (!matrix[0][k])
            row = true;

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            if (matrix[i][j] == 0) 
                matrix[i][0] = matrix[0][j] = 0;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;

    if (row) 
        for (int k = 0; k < n; k++)
            matrix[0][k] = 0;
    if (col)
        for (int k = 0; k < m; k++)
            matrix[k][0] = 0;
}

int main() 
{

    return 0;
}
