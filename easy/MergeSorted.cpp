#include <iostream>
#include <string>
#include <vector>

#define MAXN 100

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i1 = 0, i2 = 0;
        int tmp[m+n];
        for (int i = 0; i < m + n; i++) {
            if (i1 < m) {
                if (i2 < n) 
                    tmp[i] = (A[i1] < B[i2]) ? A[i1++] : B[i2++];
                else
                    tmp[i] = A[i1++];
            }
            else 
                tmp[i] = B[i2++];
        }
        for (int i = 0; i < m + n; i++)
            A[i] = tmp[i];
    }
};

int main() {
    int A[MAXN], B[MAXN];
    int m = 10, n = 10;
    for (int i = 1; i < m; i++)
        A[i] = i * 2;
    for (int i = 0; i < n; i++) 
        B[i] = i * 2 + 1;

    Solution sol;
    sol.merge(A, m, B, n);

    for (int i = 0; i < m + n; i++)
        cout << A[i] << ' ';
    cout << endl;

    return 0;
}
