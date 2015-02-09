
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path)
{
    vector<string> dirs;
    int n = path.length();

    int bufIdx = 0;
    char buf[n];
    int dirIdx = 0;

    for (int idx = 0; idx <= n; idx ++)
    {
        if (idx == n || path[idx] == '/')
        {
            if (bufIdx != 0) // then check what's inside buf
            {
                if (bufIdx <= 2 && buf[0] == '.')
                {
                    if (bufIdx == 2 && buf[1] == '.')
                        dirIdx = (dirIdx) ? dirIdx - 1 : dirIdx;
                }
                else
                {
                    string s(buf, buf+bufIdx);
                    if (dirIdx >= dirs.size())
                    {
                        dirs.push_back(s);
                        dirIdx ++;
                    }
                    else
                        dirs[dirIdx++] = s;
                }
            }
            bufIdx = 0;
        }
        else
            buf[bufIdx++] = path[idx];
    }

    string ans;
    ans.push_back('/');
    for (int i = 0; i < dirIdx; i++)
    {
        ans.append(dirs[i]);
        if (i != dirIdx-1)
            ans.push_back('/');
    }
    return ans;
}

int main()
{
    string p1 = "/home/";
    string p2 = "/a/./b/../../c/";
    string p3 = "/...";
    string p4 = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";

    cout << simplifyPath(p1) << endl;
    cout << simplifyPath(p2) << endl;
    cout << simplifyPath(p3) << endl;
    cout << simplifyPath(p4) << endl;
    return 0;
}
