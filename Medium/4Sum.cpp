
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > fourSum(vector<int> &num, int target)
{
    int n = num.size();
    sort(num.begin(), num.end());
    vector< vector<int> > ans;

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && num[i-1] == num[i]) continue;
        for (int j = i+1; j < n - 2; j++)
        {
            if (j > i+1 && num[j-1] == num[j]) continue;
            int sum = target - num[i] - num[j];
            int head = j + 1, tail = n - 1;
            while (head < tail)
            {
                int tmp = num[head] + num[tail];
                if (tmp == sum)
                {
                    vector<int> tmpans(4);
                    tmpans[0] = num[i];
                    tmpans[1] = num[j];
                    tmpans[2] = num[head];
                    tmpans[3] = num[tail];
                    sort(tmpans.begin(), tmpans.end());

                    ans.push_back(tmpans);

                    head ++;
                    tail --;
                    while (head < tail && num[head] == num[head-1]) head ++;
                    while (head < tail && num[tail] == num[tail+1]) tail --;
                }
                else if (tmp > sum)
                    tail --;
                else
                    head ++;
            }
        }
    }

    return ans;
}

int main()
{
    int n = 6;
    int A[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(A, A + n);

    vector< vector<int> > ans = fourSum(num, 0);
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);

    return 0;
}
