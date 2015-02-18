
#include <iostream>
#include <vector>

using namespace std;

void sortColors(int A[], int n)
{
    int buckets[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) buckets[A[i]] ++;

    int i = 0;
    for (int idx = 0; idx < 3; idx++)
        for (int j = 0; j < buckets[idx]; j++)
            A[i++] = idx;

    return ;
}
int main()
{
    int A[] = {1, 1, 1, 0, 1, 2, 0, 1};

    sortColors(A, 8);

    for (int i = 0; i < 8; i++)
        cout << A[i] << ' ';

    return 0;
}
