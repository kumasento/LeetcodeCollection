#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;

    int n = s.length();
    int last = -1;
    int maxl = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') 
            st.push(i);
        else if (s[i] == ')') {
            if (st.empty())
                last = i;
            else {
                st.pop();
                if (st.empty())
                    maxl = max(maxl, i - last);
                else
                    maxl = max(maxl, i - st.top());
            }
        }
    }

    return maxl;
}

int main() {
    
    return 0;
}
