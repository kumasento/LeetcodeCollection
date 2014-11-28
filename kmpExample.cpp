#include <iostream>
#include <string>
#include <cstring>

void kmp_table(char *W, int *T) {
    int pos = 2, cnd = 0;
    int len = strlen(W);

    T[0] = -1, T[1] = 0;
    while (pos < len) {
        if (W[pos-1] == W[cnd]) T[pos++] = cnd + 1, cnd ++;
        else if (cnd > 0) cnd = T[cnd];
        else T[pos++] = 0;
    }
}

int kmp_search(char *S, char *W) {
    int m = 0, i = 0; 
    int T[strlen(W)];

    kmp_table(W, T);

    while (m + i < strlen(S)) {
        if (W[i] == S[m + i]) {
            if (i == strlen(W) - 1) return m;
            i ++;
        }
        else {
            if (T[i] > -1) m = m + i - T[i], i = T[i];
            else i = 0, m++;
        }
    }

    return -1;
}

using namespace std;

int main() {
    
    char *W = (char *) "ABCDABD";
    char *S = (char *) "ABCDABCDABD";

    cout << kmp_search(S, W) << endl;

    return 0;
}
