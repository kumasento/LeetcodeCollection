
#include <iostream>

using namespace std;

double pow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    bool isN = false;
    if (n < 0)
        n = -n, isN = true;

    double ans = pow(x, n/2);
    ans = ans * ans;
    if (n%2)
        ans *= x;
    return (isN) ? 1/ans : ans;
}

int main()
{
    cout << pow(2.0, 3) << endl;
    cout << pow(2.0, 2) << endl;
    cout << pow(2.0, 1) << endl;
    cout << pow(2.0, 0) << endl;
    cout << pow(2.0, -1) << endl;
    cout << pow(2.0, -2) << endl;
    cout << pow(2.0, -3) << endl;

    return 0;
}
