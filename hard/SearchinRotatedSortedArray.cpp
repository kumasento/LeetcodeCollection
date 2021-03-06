
#include <iostream>
#include <vector>

using namespace std;

int search(int A[], int n, int target)
{
    int l = 0, r = n-1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (A[m] == target)
            return m;
        // if A[m] < target; but we do not know which part should we search
        else if (A[m] < A[r]) // then [m+1, r] is sorted
        {
            if (target > A[m] && target <= A[r])
                l = m + 1;
            else
                r = m - 1;
        }
        else
        {
            if (target >= A[l] && target < A[m])
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return -1;
}

int main() 
{
    int A[] = { 4, 5, 6, 7, 0, 1, 2 };

    cout << search(A, 7, 6) << endl;

    return 0;
}
