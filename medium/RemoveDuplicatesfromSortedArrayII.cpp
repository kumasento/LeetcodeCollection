
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(int A[], int n)
{
    int sum = 0; // store length of removed array
    int state = 0;
    // take this problem as a finite-state machine
    // state 0: just single number;
    // state 1: same as the previous number;
    // state 2: twice duplicate
    //
    // about the last element:

    int B[n];
    for (int i = 0; i < n; i++)
    {
        if (i == n-1 && state != 2)
        {
            B[sum++] = A[i];
            break;
        }
        switch (state)
        {
            case 0:
                // to state 1
                if (A[i] == A[i+1]) state = 1;
                // else no move
                B[sum++] = A[i];
                break;
            case 1:
                // to state 0
                if (A[i] != A[i+1]) state = 0;
                // to state 2
                else state = 2;
                B[sum++] = A[i];
                break;
            case 2:
                // to state 0
                if (A[i] != A[i+1]) state = 0;
                // remain
                else  state = 2;
        }
    }
    for (int i = 0; i < sum; i++)
        A[i] = B[i];
    for (int i = sum; i < n; i++)
        A[i] = 0;

    return sum;
}

int main()
{
    int A[] = {1, 1, 1, 2, 2, 3};
    cout << removeDuplicates(A, 6) << endl;

    return 0;
}
