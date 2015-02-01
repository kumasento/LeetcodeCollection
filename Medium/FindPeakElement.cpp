
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int> &num)
{
    int n = num.size();
    if (n == 0) return -1;

    for (int i = 0; i < n; i++)
    {
        bool prev = true, next = true;
        if (i != 0)
            prev = num[i] > num[i-1];
        if (i != n-1)
            next = num[i] > num[i+1];
        if (prev && next)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);

    cout << findPeakElement(A) << endl;

    return 0;
}
