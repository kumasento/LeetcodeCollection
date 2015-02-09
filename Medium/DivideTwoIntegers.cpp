
#include <iostream>
#include <climits>

using namespace std;

int divide(int dividend, int divisor)
{
    long long ans = 0;
    if (!divisor)
        return INT_MAX;
    if (dividend == INT_MIN)
    {
        dividend += abs(divisor);
        if (divisor == -1)
            return INT_MAX;
        ans ++;
    }
    if (divisor == INT_MIN)
        return ans;
    long long dd = dividend;
    long long ds = divisor;
    dd = (dd < 0) ? -dd : dd;
    ds = (ds < 0) ? -ds : ds;

    while (ds <= dd)
    {
        int i;
        long long a = ds;
        for (i = 0; a <= dd; i++)
            a <<= 1; // a = a * 2
        ans += 1 << (i-1);
        dd -= (ds << (i-1));
    }

    ans = (dividend>0 ^ divisor>0) ? -ans : ans;

    if (ans < (long long)INT_MIN || ans > (long long)INT_MAX)
        return INT_MAX;
    return ans;
}

int main()
{
    cout << divide(INT_MIN, -1) << endl;

    return 0;
}
