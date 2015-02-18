#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
    int strStr(char *haystack, char *needle) {
        if (strlen(needle) == 0)
            return 0;
        int l1 = strlen(haystack), l2 = strlen(needle);

        int i, j;
        for (i = 0; i < l1; i++) {
            if (strncmp(haystack+i, needle, strlen(needle)) == 0)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.strStr("", "") << endl;
    cout << sol.strStr("abc", "d") << endl;
    cout << sol.strStr("abc", "ab") << endl;

    return 0;
}
