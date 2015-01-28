
#include <iostream>
#include <vector>

using namespace std;

// why this algorithm will work?
// where will l and r locate?
// when will it stop? -> l > r
// l >= r + 1
// previously m must equal to r or l;
// A[m] < target and then l = m+1, m = r. So A[r] < target.
// A[m] > target and then r = m-1, m = l. So A[l] > target.
//
// if I return l, then A[l] > target or A[l-1] < target.
// then l is the target point.

int searchInsert(int A[], int n, int target)
{
    int l = 0, r = n-1, m;
    while (l <= r)
    {
        m = (l+r) / 2;
        if (A[m] == target)
            return m;
        else if (A[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int main() 
{
    int A[] = {1,3,5,6};
    cout << searchInsert(A, 4, 5) << endl;
    cout << searchInsert(A, 4, 2) << endl;
    cout << searchInsert(A, 4, 7) << endl;
    cout << searchInsert(A, 4, 0) << endl;

    return 0;
}
