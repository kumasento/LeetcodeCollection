#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string s) {
    if (s.length() == 1) 
        return s[0] != '0';
    if (s.length() == 2) 
        return (s[0] == '1' && s[1] >= '0' && s[1] <= '9') 
            || (s[0] == '2' && s[1] >= '0' && s[1] <= '6');
    return false;       
}

int numDecodings(string s) {
    int n = s.length();
    vector<int> f(n+1, 0);

    f[0] = (check(s.substr(0, 1))) ? 1 : 0;
    for (int i = 1; i < n; i++) {
        f[i] += (check(s.substr(i,1))) ? f[i-1] : 0;
    
        if (i == 1) 
            f[i] += (check(s.substr(i-1, 2))) ? 1 : 0; 
        else if (f[i-2]) 
            f[i] += (check(s.substr(i-1, 2))) ? f[i-2] : 0;
    }

    return f[n-1];
}

int main() {
    cout << numDecodings(string("17")) << endl;

    return 0;
}
