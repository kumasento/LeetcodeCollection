
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target)
{
    vector<int> res(2, -1);

    int l = 0, r = n-1, m;
    // first check the existance.
    while (l <= r)
    {
        m = (l+r) / 2;
        if (A[m] == target)
            break;
        else if (A[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    if (A[m] != target)
        return res;
    l = 0, r = m;
    while (l <= r)
    {
        m = (l+r)/2;
        if (A[m] >= target)
            r = m - 1;
        else
            l = m + 1;
    }
    res[0] = l;
    l = m, r = n-1;
    while (l <= r)
    {
        m = (l+r)/2;
        if (A[m] <= target)
            l = m + 1;
        else 
            r = m - 1;
    }
    res[1] = r;
    return res;
}

int main() 
{
    int A[] = {5, 7, 7, 8, 8, 10};
    int n = 6;
    int target = 7;

    vector<int> res = searchRange(A, n, target);
    cout << res[0] << ' ' << res[1] << endl;

    return 0;
}
