
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    if (n == 0)
        return ans;
    if (n == 1)
    {
        ans.push_back(string("()"));
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        vector<string> t1 = generateParenthesis(i);
        vector<string> t2 = generateParenthesis(n-i-1);

        for (int j = 0; j < t1.size(); j++)
            t1[j] = string("(") + t1[j] + string(")");
        if (!t1.size())
            t1.push_back(string("()"));

        for (int j = 0; j < t2.size(); j++)
            for (int k = 0; k < t1.size(); k++)
                ans.push_back(t1[k] + t2[j]);
        if (!t2.size())
            for (int k = 0; k < t1.size(); k++)
                ans.push_back(t1[k]);
    }

    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
