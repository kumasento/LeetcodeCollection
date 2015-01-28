
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
    int id, num;
    item(int id, int num):num(num), id(id) {}
    friend bool operator < (item a, item b) { return a.num < b.num; }
};

vector< vector<int> > threeSum(vector<int> &num)
{
    vector< vector<int> > res;

    int n = num.size();
    if (n <= 2) return res;

    vector<item> items;
    for (int i = 0; i < n; i++)
        items.push_back(item(i+1, num[i]));
    sort(items.begin(), items.end());

    for (int t = 0; t < n-2; t++)
    {
        int target = -items[t].num;
        if (t != 0 && target == -items[t-1].num)
            continue;
        int head = t+1, tail = n-1;
        while (head < tail)
        {
            int sum = items[head].num + items[tail].num;
            if (target == sum)
            {
                vector<int> ans(3);
                ans[0] = items[t].num;
                ans[1] = items[head].num;
                ans[2] = items[tail].num;
                sort(ans.begin(), ans.end());

                res.push_back(ans);

                head ++;
                tail --;
                while (head < tail && items[head].num == items[head-1].num)
                    head ++;
                while (head < tail && items[tail].num == items[tail+1].num)
                    tail --;
            }
            else if (target < sum)
                head ++;
            else
                tail --;
        }
    }

    return res;
}

int main() 
{
    int A[] = {1, 0, 0, 0};
    vector<int> num(A, A + 4);
    vector< vector<int> > res = threeSum(num);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << endl;
    return 0;
}
