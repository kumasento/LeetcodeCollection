
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num)
{
    int digits[4];
    int scale = 1000;
    int t = num;
    for (int i = 0; i < 4; i++, scale /= 10)
        digits[i] = t / scale, t = t % scale;

    string ans;
    // thousands
    for (int i = 0; i < digits[0]; i++)
        ans.push_back('M');

    // hundreds
    if (digits[1] == 9)
        ans.append("CM");
    else if (digits[1] == 4)
        ans.append("CD");
    else
    {
        if (digits[1] >= 5)
            for (int i = 0; i <= digits[1] - 5; i++)
                ans.push_back((i == 0) ? 'D' : 'C');
        else
            for (int i = 0; i < digits[1]; i++)
                ans.push_back('C');
    }

    // ten
    if (digits[2] == 9)
        ans.append("XC");
    else if (digits[2] == 4)
        ans.append("XL");
    else
    {
        if (digits[2] >= 5)
            for (int i = 0; i <= digits[2] - 5; i++)
                ans.push_back((i == 0) ? 'L' : 'X');
        else
            for (int i = 0; i < digits[2]; i++)
                ans.push_back('X');
    }

    // one
    if (digits[3] == 9)
        ans.append("IX");
    else if (digits[3] == 4)
        ans.append("IV");
    else
    {
        if (digits[3] >= 5)
            for (int i = 0; i <= digits[3] - 5; i++)
                ans.push_back((i == 0) ? 'V' : 'I');
        else
            for (int i = 0; i < digits[3]; i++)
                ans.push_back('I');
    }

    return ans;
}

int main()
{
    cout << intToRoman(2015) << endl;
    cout << intToRoman(1954) << endl;
    cout << intToRoman(1990) << endl;
    cout << intToRoman(2014) << endl;

    return 0;
}
