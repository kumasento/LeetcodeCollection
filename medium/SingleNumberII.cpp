
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(int A[], int n)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
        twos |= (ones & A[i]);
        ones ^= A[i];
        int x = ~(twos & ones);
        ones &= x;
        twos &= x;
    }
    return ones;
}

int main()
{
    int A[] = {1,1,1,2};
    cout << singleNumber(A, 4) << endl;


    return 0;
}
