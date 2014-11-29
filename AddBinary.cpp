#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string addBinary(string a, string b) {
        int al = a.length(), bl = b.length();
        
        int g = 0;
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; g != 0 || i < al || i < bl; i++) {
            int p1 = 0, p2 = 0;
            if (i < al) p1 = a[i] - '0';
            if (i < bl) p2 = b[i] - '0';

            int sum = p1 + p2 + g;
            g = sum / 2;
            
            ans.push_back(sum % 2 + '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string a = "1010";
    string b = "1011";
    
    Solution sol;
    cout << sol.addBinary(a, b) << endl;

    return 0;
}

