
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// in these 2 functions, src and result strings are all reversed

string add(string a, string b)
{
    string ans;
    int g = 0;
    int p = 0, q = 0;
    int la = a.length();
    int lb = b.length();

    while (g != 0 || p != la || q != lb)
    {
        int p1 = 0, p2 = 0;
        if (p != la) p1 = a[p++]-'0';
        if (q != lb) p2 = b[q++]-'0';
        int sum = g + p1 + p2;
        g = sum / 10;
        ans.push_back((sum%10)+'0');
    }

    return ans;
}

string times(string a, char b)
{
    string ans;
    int g = 0;
    int p = 0;
    int l = a.length();

    if (b == '0')
        return string("0");

    while (g != 0 || p != l)
    {
        int t = (p != l) ? a[p++]-'0' : 0;
        int v = b-'0';
        int sum = t * v + g;
        g = sum / 10;
        ans.push_back((sum % 10) + '0');
    }
    return ans;
}

string multiply(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans = string("0");
    int p = 0;

    if (a.length() < b.length())
        swap(a, b);
    int l1 = a.length(), l2 = b.length();

    for (int p = 0; p < l2; p++)
    {
        char t = b[p];
        string tmp = times(a, t);
        for (int i = 0; i < p; i++)
            tmp.insert(tmp.begin(), '0');
        ans = add(ans, tmp);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main()
{
    cout << add(string("321"), string("32")) << endl;
    cout << times(string("321"), '4') << endl;
    cout << multiply(string("123"), string("11")) << endl;
    cout << multiply(string("9133"), string("0")) << endl;
    return 0;
}
