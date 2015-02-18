
#include <iostream>

using namespace std;

int singleNumber(int A[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= A[i];
    return ans;
}

int main()
{
    int A[] = {1,2,1};
    cout << singleNumber(A, 3) << endl;

    return 0;
}
