#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        sort(numbers.begin(), numbers.end());
        
        vector<int> ans(2);

        int i = 0, j = numbers.size()-1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
            else if (numbers[i] + numbers[j] > target) 
                j --;
            else
                i ++;
        }

        return ans;
    }
};

int main() {
    int S[] = {3,2,4};
    int target = 6;

    vector<int> numbers(S, S+sizeof(S)/sizeof(int));

    Solution sol;
    vector<int> ans = sol.twoSum(numbers, target);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
