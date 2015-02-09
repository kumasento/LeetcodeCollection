
#include <iostream>

using namespace std;

int sqrt(int x)
{
    if (x == 0) return 0;
    double last = 0, res = x;
    while (res != last)
    {
        last = res;
        res = (res + x/res) / 2;
    }
    return (int) res;
}

int main()
{

    return 0;
}
