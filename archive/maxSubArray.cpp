#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int maxSubArray(int A[], int n) {
    if (n == 0) return 0;
    if (n == 1) return A[0];

    int mid = n / 2;
    int left_length = mid;
    int right_length = n - mid;

    int left_max = maxSubArray(A, left_length);
    int right_max = maxSubArray(A+mid, right_length);
    int maxsum = (left_max > right_max) ? left_max : right_max;

    int sum = 0;
    int maxmid = INT_MIN;
    for (int i = mid; i >= 0; i--) {
        sum += A[i];
        maxmid = (sum > maxmid) ? sum : maxmid;
    }
    sum = maxmid;
    for (int i = mid + 1; i < n; i++) {
        sum += A[i];
        maxmid = (sum > maxmid) ? sum : maxmid;
    }

    maxsum = (maxsum > maxmid) ? maxsum : maxmid;

    return maxsum;
}

int main() {
    puts("Please Enter The Length:");
    int N; scanf("%d", &N);
    puts("Enter All the N numbers: ");
    int A[N]; for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    printf("The Result is %d\n", maxSubArray(A, N));

    return 0;
}
