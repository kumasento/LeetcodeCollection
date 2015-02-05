
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    const int alpha_num = 256;
    int hash[alpha_num];
    int max_length = 0;
    int start = 0;
    int len = 0;

    for (int i = 0; i < alpha_num; i++)
        hash[i] = -1;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (hash[c] == -1)
        {
            hash[c] = i;
            len ++;
        }
        else
        {
            int pos = hash[c];
            if (pos < start || pos == -1) // will not effect the current substring
                hash[c] = i, len++; // still update
            // [pos, i]
            else
            {
                max_length = (len > max_length) ? len : max_length;
                // found!
                start = pos + 1;
                len = i - start + 1;
                hash[c] = i;
            }
        }
    }
    max_length = (len > max_length) ? len : max_length;

    return max_length;
}

int main()
{
    cout << lengthOfLongestSubstring(string("bbbbb")) << endl;
    cout << lengthOfLongestSubstring(string("abcabcbb")) << endl;
    cout << lengthOfLongestSubstring(string("abc")) << endl;

    return 0;
}
