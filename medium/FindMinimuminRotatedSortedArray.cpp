
#include <iostream>
#include <vector>

using namespace std;
int findMinRecur(vector<int> &num, int L, int R)
{
    if (L == R)
        return num[L];
    if (L == R-1)
        return (num[L] < num[R]) ? num[L] : num[R];
    int M = (L+R) / 2;
    if (num[M] > num[R])
        return findMinRecur(num, M+1, R);
    else
        return findMinRecur(num, L, M);

}

int findMin(vector<int> &num)
{
    return findMinRecur(num, 0, num.size()-1);
}


int main()
{
    int A[] = {1, 2, 3, 0};
    vector<int> num(A, A + 4);
    cout << findMin(num) << endl;
    return 0;
}
