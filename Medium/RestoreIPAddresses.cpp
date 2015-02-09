
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

bool valid(string s, int start, int len)
{
    if (len <= 0 || len > 3)
        return false;
    string ss = s.substr(start, len);
    if (ss.length() > 1 && ss[0] == '0')
        return false;
    int num = atoi(ss.c_str());
    return num <= 255;
}

vector<string> restoreIpAddresses(string s)
{
    int n = s.length();
    vector<string> ans;
    if (n < 4)
        return ans;
    for (int i = 0; i < n-3 && i < 3; i++)
        for (int j = i+1; j < n-2 && j-i <= 3; j++)
            for (int k = j+1; k < n-1 && k-j <= 3; k++)
            {
                int l1 = i+1;
                int l2 = j-i;
                int l3 = k-j;
                int l4 = n-1-k;
                if (valid(s, 0, l1) && valid(s, i+1, l2)
                        && valid(s, j+1, l3) && valid(s, k+1, l4))
                {
                    string res = s;
                    res.insert(i+1, ".");
                    res.insert(j+2, ".");
                    res.insert(k+3, ".");
                    ans.push_back(res);
                }
            }
    return ans;
}

int main()
{
    string ip("010010");

    vector<string> ans = restoreIpAddresses(ip);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
