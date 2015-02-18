
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int encodeChar(char c)
{
    switch (c)
    {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
    }
}

char decodeChar(int i)
{
    switch (i)
    {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

int encode(string str)
{
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
        ans |= ((encodeChar(str[i]))<<(i*2));
    return ans;
}

string decode(int ans)
{
    string a;
    for (int i = 0; i < 10; i++)
        a.push_back(decodeChar((ans>>(i*2)) & 0x3));
    return a;
}

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> ans;
    if (s.length() <= 10)
        return ans;

    unordered_map<int,int> hash;
    for (int i = 0; i + 10 <= s.length(); i++)
    {
        string substr = s.substr(i, 10);
        hash[encode(substr)] ++;
    }

    for (unordered_map<int,int>::iterator iter = hash.begin();
            iter != hash.end();
            iter ++)
        if (iter->second > 1)
            ans.push_back(decode(iter->first));

    return ans;
}

int main()
{
    vector<string> ans = findRepeatedDnaSequences(string("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
