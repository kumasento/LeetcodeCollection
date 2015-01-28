
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome(string s)
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

int main()
{
    string s1 = string("aaa");
    string s2 = string("aabac");
    string s3 = string("abb");
    string s4 = string("aaaa");
    string s5 = string("aaaabaaa");
    cout << longestPalindrome(s1) << endl;
    cout << longestPalindrome(s2) << endl;
    cout << longestPalindrome(s3) << endl;
    cout << longestPalindrome(s4) << endl;
    cout << longestPalindrome(s5) << endl;
    return 0;
}
