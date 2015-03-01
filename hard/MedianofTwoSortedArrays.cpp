
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

double findKth(int A[], int m, int B[], int n, int k) {
    if (m >= n)
        return findKth(B, n, A, m, k);
    if (m == 0)
        return B[k-1];
    if (k == 1)
        return min(A[0], B[0]);
    int pa = min(k/2, m), pb = min(k/2, n);
    if (A[pa-1] < B[pb-1])
        return findKth(A+pa, m-pa, B, n, k-pa);
    if (A[pa-1] > B[pb-1])
        return findKth(A, m, B+pb, n-pb, k-pb);
    return A[pa-1];
}


double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m+n)%2)
        return findKth(A, m, B, n, (m+n)/2+1);
    else
        return (findKth(A, m, B, n, (m+n)/2)
                + findKth(A, m, B, n, (m+n)/2+1)) /2;
}

int main() {

    return 0;
}
