
#include <iostream>
#include <vector>

using namespace std;

bool canJump(int A[], int n)
{
    int upper_bound = 0;
    for (int i = 0; i <= upper_bound && i < n; i++)
        upper_bound = (A[i]+i > upper_bound) ? (A[i]+i) : upper_bound;
    return upper_bound >= n-1; // if it reaches the end
}

int main()
{
    int A[] = {2,3,1,1,4};
    int B[] = {3,2,1,0,4};
    int C[] = {0};
    int D[] = {1,0};
    cout << canJump(A, 5) << endl;
    cout << canJump(B, 5) << endl;
    cout << canJump(C, 1) << endl;
    cout << canJump(D, 2) << endl;
    return 0;
}
