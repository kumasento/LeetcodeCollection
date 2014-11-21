
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int i, j;
        string ans;
        if (strs.size() <= 0) 
            return "";
        for (i = 0; i < strs[0].length(); i++) { 
            char c = strs[0][i];
            for (j = 1; j < strs.size(); j++) 
                if (i >= strs[j].length() || strs[j][i] != c) 
                    break;
            if (j < strs.size()) 
                break;
            else 
                ans.push_back(c);
        }
        return ans;
    }
};

int main() {

    Solution sol;

    vector<string> strs;
    //strs.push_back("abcdef");
    //strs.push_back("abc");

    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
