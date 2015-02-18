
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector< vector<int> > &matrix)
{   
    int n = matrix.size();
    // swap along the reverse diagno
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n/2; j++)
            swap(matrix[i][j], matrix[i][n-j-1]);
}

int main()
{
    

    return 0;
}
