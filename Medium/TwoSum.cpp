
#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>

using namespace std;

struct item
{
    int num, id;
    item(int num, int id): num(num), id(id) {}
    friend bool operator < (item a, item b)
    {
        return a.num < b.num;
    }
};


vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<item> items;
    for (int i = 0; i < numbers.size(); i++)
        items.push_back(item(numbers[i], i));
    sort(items.begin(), items.end());

    int n = numbers.size();
    int head = 0, tail = n-1;
    while (head < tail)
    {
        int sum = items[head].num + items[tail].num;
        if (sum == target)
            break;
        else if (sum > target)
            tail--;
        else
            head++;
    }
    vector<int> res(2);
    res[0] = items[head].id + 1;
    res[1] = items[tail].id + 1;
    if (res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main()
{
    vector<int> A(4);
    A[0] = 2;
    A[1] = 7;
    A[2] = 11;
    A[3] = 15;
    int target = 9;

    vector<int> res = twoSum(A, target);
    cout << res[0] << ' ' << res[1] << endl;

    return 0;
}
