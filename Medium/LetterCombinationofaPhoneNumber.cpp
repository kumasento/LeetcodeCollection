#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans; 
        if (digits.length() == 0) { ans.push_back(string("")); return ans; }
        
        string next;
        for (int i = 1; i < digits.length(); i++)
            next.push_back(digits[i]);

        vector<string> tmp = letterCombinations(next);

        string now;
        now.push_back(digits[0]);

        for (int i = 0; i < tmp.size(); i++) {
            if (now == string("2")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "a");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "b");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "c");
            }
            else if (now == string("3")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "d");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "e");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "f");
            }
            else if (now == string("4")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "g");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "h");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "i");
            }
            else if (now == string("5")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "j");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "k");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "l");
            }
            else if (now == string("6")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "m");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "n");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "o");
            }
            else if (now == string("7")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "p");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "q");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "r");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "s");
            }
            else if (now == string("8")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "t");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "u");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "v");
            }
            else if (now == string("9")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "w");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "x");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "y");
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, "z");
            }
            else if (now == string("0")) {
                ans.push_back(tmp[i]); ans[ans.size()-1].insert(0, " ");
            }
        }

        return ans;
    }
};

int main() {
    string digits = "234";

    Solution sol;
    
    vector<string> ans = sol.letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
