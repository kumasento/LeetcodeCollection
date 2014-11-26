#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (int i = 0; i < s.length(); i++) {
            if (S.empty()) { 
                S.push(s[i]);
                continue;
            }
            char top = S.top();
            char match = s[i];

            if (match == '(' || match == '[' || match == '{')
                S.push(match);
            else if ((top == '(' && match == ')') ||
                     (top == '[' && match == ']') ||
                     (top == '{' && match == '}')) 
                S.pop();
            else
                return false;
        }
        return S.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("((()))") << endl;
    cout << s.isValid("(([)))") << endl;
    cout << s.isValid("((])))") << endl;
    
    return 0;
}
