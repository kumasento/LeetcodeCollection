
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome_Dp(string s)
{
    int n = s.length();
    bool dp[n][n];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j++)
            if (i >= j)
                dp[i][j] = true;
            else
                dp[i][j] = false;

    int head, tail, max = 0;

    for (int l = 2; l <= n; l++)
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i+1][j-1];
                if (dp[i][j] && l > max)
                    max = l, head = i, tail = j;
            }
            else
                dp[i][j] = false;
        }

    return s.substr(head, tail-head+1);
}

string longestPalindrome(string s)
{
    // manacher's algorithm
    // first expand the original string s
    int n = s.length();
    char special_character = '#';
    string ss;
    ss.push_back('$');
    for (int i = 0; i < n; i++)
    {
        ss.push_back(special_character);
        ss.push_back(s[i]);
    }
    ss.push_back(special_character);

    // then calculate p
    n = ss.length();
    int mx = 0, id = 0; // mx is the max boundary, id is the middle char
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++)
    {
        p[i] = (mx > i) ? min(p[id*2-i], mx-i) : 1;
        while (ss[i+p[i]] == ss[i-p[i]]) p[i]++;
        if (i + p[i] > mx)
            id = i, mx = i + p[i];
    }

    int max_val = p[0], max_id = 0;
    for (int i = 1; i < n; i++)
        if (p[i] > max_val)
            max_id = i, max_val = p[i];

    int head = max_id - (p[max_id]-1);
    int len = 2 * p[max_id] - 1;
    string ans = ss.substr(head, len);
    cout << ans << endl;
    for (int i = 0; i < ans.length(); i++)
        if (ans[i] == '#')
            ans.erase(i, 1);
    return ans;
}

int main()
{
    string s0 = string("a");
    string s1 = string("aaa");
    string s2 = string("aabac");
    string s3 = string("abb");
    string s4 = string("aaaa");
    string s5 = string("aaaabaaa");
    cout << longestPalindrome(s0) << endl;
    cout << longestPalindrome(s1) << endl;
    cout << longestPalindrome(s2) << endl;
    cout << longestPalindrome(s3) << endl;
    cout << longestPalindrome(s4) << endl;
    cout << longestPalindrome(s5) << endl;
    return 0;
}
