
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string pre;
        for (int i = 0; i < s.length(); i++) 
            if (isalnum(s[i]))
                pre.push_back(tolower(s[i]));

        int len = pre.length();
        for (int i = 0; i <= len-i-1; i++) 
            if (pre[i] != pre[len-i-1]) 
                return false;
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;

    return 0;
}
