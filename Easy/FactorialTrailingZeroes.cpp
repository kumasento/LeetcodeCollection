#include <iostream>

using namespace std;

int trailingZeroes(int n) {
    // count all the 2 5 and 10?
    // it's 2 and 5 in n!
    // what about n?
    // 2 is far more than 5, so just count 5
    // how many 5 will appear?
    // take 10! for example, there're only 10 and 5

    int cnt = 0;
    while (n != 0) {
        n /= 5;
        cnt += n;
    }
    return cnt;
}

int main() {
    cout << trailingZeroes(15) << endl;
    cout << trailingZeroes(150) << endl;
    cout << trailingZeroes(1500) << endl;

    return 0;
}
