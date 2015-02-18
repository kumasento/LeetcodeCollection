
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> anagrams(vector<string> &strs)
{
    // foreach string in strs, check if it's one of the anagrams
    // for example, I have "warned", and now I'm checking "andrew"
    // then "andrew" and "warned" are in one group of anagrams
    //
    // 1. identity: sorted string
    // 2. storage: if it matched, just store
    unordered_map<string, int> hash;
    vector<string> res;
    int n = strs.size();
    if (n <= 0)
        return vector<string>();
    for (int i = 0; i < n; i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        if (hash.find(s) == hash.end())
            hash.insert(pair<string, int>(s, i));
        else
        {
            if (hash[s] >= 0)
            {
                res.push_back(strs[hash[s]]);
                hash[s] = -1;
            }
            res.push_back(strs[i]);
        }
    }
    return res;
}

int main()
{
    vector<string> strs;
    strs.push_back(string("warned"));
    strs.push_back(string("andrew"));
    strs.push_back(string("wander"));
    return 0;
}
