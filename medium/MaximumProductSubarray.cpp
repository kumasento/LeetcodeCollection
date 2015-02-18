#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        int min_local = A[0];
        int max_local = A[0];
        int global = A[0];

        for (int i = 1; i < n; i++) {
            int max_copy = max_local;
            // find max in {A[i], A[i]*max_local, A[i]*min_local}
            // find min in {A[i], A[i]*max_local, A[i]*min_local}
            max_local = max(max(A[i] * max_local, A[i]), A[i] * min_local);
            min_local = min(min(A[i] * max_copy, A[i]), A[i] * min_local);
            // max global is among all these 2 values
            global = max(global, max_local);
        }

        return global;
    }       
};

int main() {
    int A[] = {2, 3, -2, 4};
    int B[] = {-2};
    Solution sol;
    cout << sol.maxProduct(A, 4) << endl;
    cout << sol.maxProduct(B, 1) << endl;

    return 0;
}
