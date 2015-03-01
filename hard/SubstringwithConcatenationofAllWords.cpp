
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> ans;
    map<string, int> dict;
    map<string, int>::iterator iter;
    for (int i = 0; i < L.size(); i++)
        dict[L[i]] += 1;
    int I = L[0].length();
    for (int start_idx = 0; start_idx < I; start_idx++) {
        int left_idx = start_idx;
        int right_idx = start_idx + I;
        while (left_idx < S.length() && left_idx+L.size()*I < S.length()) {
            map<string, int> tmp_dict;
            string word = S.substr(left_idx, I);
            tmp_dict[word] += 1;
            while (dict.find(word) != dict.end()
                    && dict[word] >= tmp_dict[word]) {
                if (right_idx-left_idx==L.size()*I) {
                    ans.push_back(left_idx);
                    break;
                }
                word = S.substr(right_idx, I);
                tmp_dict[word] += 1;
                right_idx += I;
            }
            left_idx += I;
            right_idx = left_idx + I;
            if (right_idx >= S.length())
                break;
        }
    }
    return ans;
}

int main() {
    string S = "abababab";
    vector<string> L;
    L.push_back(string("a"));
    L.push_back(string("b"));
    L.push_back(string("a"));
    vector<int> ans = findSubstring(S, L);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
