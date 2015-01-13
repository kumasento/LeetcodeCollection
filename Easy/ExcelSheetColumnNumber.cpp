#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int titleToNumber(string s) {
    int n = s.length();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int p = s[i] - 'A' + 1;
        sum = sum * 26 + p;
    }

    return sum;
}

int main() {

    cout << titleToNumber(string("AA")) << endl;
    cout << titleToNumber(string("BA")) << endl;

    return 0;
}
