
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    int n = s.length();
    vector<bool> f(n+1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {  
            // first check if [0:j] is a matched string
            if (f[j]) {
            // next check the suffix
                string suf = s.substr(j, i-j);
              
                if (dict.find(suf) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        if (!f[i])
            f[i] = dict.find(s.substr(0, i)) != dict.end();
        //cout << i << ' ' << f[i] << endl;
    }

    return f[n];
}

int main() {
    string s = "leetcode";

    unordered_set<string> dict;
    dict.insert("le");
    dict.insert("et");
    dict.insert("code");

    cout << wordBreak(s, dict) << endl;

    return 0;

}
