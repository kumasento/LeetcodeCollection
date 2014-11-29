#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> words;
        string word;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && word.length() > 0) 
                words.push(word), word = string("");
            else if (s[i] != ' ') 
                word.push_back(s[i]);
        }
        if (word.length() > 0) 
            words.push(word), word = string("");

        string ans;
        // merge
        while (!words.empty()) {
            word = words.top();
            words.pop();
            if (ans.length() > 0) ans.push_back(' ');
            ans.append(word);
        }

        s = ans;
    }
};

int main() {
    string prev("the sky is blue");
    
    Solution sol;
    sol.reverseWords(prev);

    cout << "["  << prev << "]" << endl;

    return 0;
}
