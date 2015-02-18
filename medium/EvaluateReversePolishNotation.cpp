#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numStack;
        for (int i = 0; i < tokens.size(); i++) {
            string str = tokens[i];
            if (str == "+") {
                int n1 = numStack.top(); numStack.pop();
                int n2 = numStack.top(); numStack.pop();
                numStack.push(n1+n2);
            } else if (str == "-") {
                int n1 = numStack.top(); numStack.pop();
                int n2 = numStack.top(); numStack.pop();
                numStack.push(n2-n1);
            } else if (str == "*") {
                int n1 = numStack.top(); numStack.pop();
                int n2 = numStack.top(); numStack.pop();
                numStack.push(n1*n2);
            } else if (str == "/") {
                int n1 = numStack.top(); numStack.pop();
                int n2 = numStack.top(); numStack.pop();
                numStack.push(n2/n1);
            } else {
                numStack.push(atoi(str.c_str()));
            }
        }

        return numStack.top();
    }
};

int main() {
    vector<string> eval1;
    eval1.push_back("2");
    eval1.push_back("1");
    eval1.push_back("+");
    eval1.push_back("3");
    eval1.push_back("*");

    vector<string> eval2;
    eval2.push_back("4");
    eval2.push_back("13");
    eval2.push_back("5");
    eval2.push_back("/");
    eval2.push_back("+");

    Solution sol;
    cout << sol.evalRPN(eval1) << endl;
    cout << sol.evalRPN(eval2) << endl;
}
