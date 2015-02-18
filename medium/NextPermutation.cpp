
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &num)
{
    int n = num.size();
    // find num[i] < num[i+1]
    if (n == 1) return ;
    for (int i = n-2, ii = n-1; i >= 0; i--, ii--)
    {
        if (num[i] < num[ii])
        {
            int j = n-1;
            while (num[j] <= num[i]) j--;
            swap(num[i], num[j]);
            reverse(num.begin() + ii, num.end());
            return ;
        }
    }
    reverse(num.begin(), num.end());
    return ;
}

int main()
{
    int A[] = {1, 3, 2, 4, 5};
    vector<int> num(A, A+5);

    nextPermutation(num);

    for (int i = 0; i < num.size(); i++)
        cout << num[i] << ' ';
    cout << endl;

    return 0;
}
