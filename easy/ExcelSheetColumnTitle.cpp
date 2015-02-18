
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string convertToTitle(int n) {
    string ans;
   
    while (n != 0) {
        char c = (n-1) % 26 + 'A';
        ans.push_back(c);
        if (n % 26 == 0) n--; // if it mod 26, then reduce 1
        n /= 26;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    for (int i = 0; i < 100; i++)
        cout << i+1 << ' ' << convertToTitle(i+1) << endl;
    return 0;
}

