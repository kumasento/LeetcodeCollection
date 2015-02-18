
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > threeSum(vector<int> &num, int target)
{
    int n = num.size();
    sort(num.begin(), num.end());
    for (int i = 0; i < n - 2; i++)
    {
        int t = target - num[i];
        int head = i+1, tail = n-1;
        while (head < tail)
        {
            if (num[head] + num[tail] == t)
            {

            }
        }
    }
}

vector< vector<int> > fourSum(vector<int> &num, int target)
{

}

int main()
{

    return 0;
}
