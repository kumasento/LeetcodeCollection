
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    // There's a common path for these problems
    // 1. check if it's zero
    if (numerator == 0)
        return string("0");

    string result;
    // 2. check if it's minus
    if ((numerator < 0) ^ (denominator < 0))
        result.push_back('-');
    // take care of the overflow;
    long long n = numerator, d = denominator;
    n = abs(n);
    d = abs(d);

    // 3. take the Z part
    result.append(to_string(n/d));

    // 4. take the float part
    long long r = n % d;
    if (!r)
        return result;
    result.push_back('.');

    unordered_map<int, int> hash;
    while (r)
    {
        if (hash.find(r) != hash.end())
        { // start to loop
            result.insert(hash[r], 1, '(');
            result.push_back(')');
            break;
        }
        hash[r] = result.size();
        r *= 10;
        result.append(to_string(r/d));
        r = r%d;
    }

    return result;
}

int main()
{
    cout << fractionToDecimal(1,2) << endl;
    cout << fractionToDecimal(2,1) << endl;
    cout << fractionToDecimal(2,3) << endl;

    return 0;
}
