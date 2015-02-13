
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Num
{
    string n;
    Num(int num) { n = to_string(num); }
    friend bool operator < (Num an, Num bn)
    {
        string a = an.n, b = bn.n;
        return a + b > b + a;
    }
};

string largestNumber(vector<int> &num)
{
    vector<Num> Nums;
    for (int i = 0; i < num.size(); i++)
        Nums.push_back(Num(num[i]));
    sort(Nums.begin(), Nums.end());

    string ans;
    for (int i = 0; i < Nums.size(); i++)
        ans.append(Nums[i].n);

    // delete heading zeroes
    int start;
    for (start = 0; start < ans.length(); start++)
        if (ans[start] != '0')
            break;
    if (start == ans.length())
        return string("0");
    return ans.substr(start, ans.length()-start);
}

int main()
{
    int A[] = {3, 30, 34, 5, 9};
    int B[] = {0, 0};
    int C[] = {824,938,1399,5607,6973,5703,9609,4398,8247};
    vector<int> V1(A, A+5);
    vector<int> V2(B, B+2);
    vector<int> V3(C, C+9);

    cout << largestNumber(V1) << endl;
    cout << largestNumber(V2) << endl;
    cout << largestNumber(V3) << endl;

    return 0;
}
