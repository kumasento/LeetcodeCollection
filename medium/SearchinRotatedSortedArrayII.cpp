
#include <iostream>
#include <vector>

using namespace std;

bool search(int A[], int n, int target)
{
    int l = 0, r = n-1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (A[m] == target)
            return true;
        else if (A[l] > A[m])
        {
            if (target > A[m] && target <= A[r])
                l = m + 1;
            else
                r = m - 1;
        }
        else if (A[l] < A[m])
        {
            if (target >= A[l] && target < A[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else
            l ++;
    }
    return false;
}

int main() 
{

    return 0;
}
