#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> zigZag(nRows);
        string ans;
    
        int i, r = 0, up;
        for (i = 0; i < s.length(); i++) {
            zigZag[r].push_back(s[i]);

            if (r == 0)                 up = 0;
            else if (r == nRows - 1)    up = 1;
            if (up == 0)    r ++;
            else            r --;
        }
        
        for (r = 0; r < nRows; r++) 
            for (i = 0; i < zigZag[r].size(); i++)
                ans.push_back(zigZag[r][i]);

        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.convert("", 3) << endl;
    cout << sol.convert("A", 1) << endl;
    cout << sol.convert("AB", 2) << endl;
    cout << sol.convert("PAYPALISHIRING", 3) << endl;
    cout << sol.convert("123456789", 4) << endl;
    
    return 0;
}
