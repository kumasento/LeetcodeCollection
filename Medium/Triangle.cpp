#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minimumTotal(vector< vector<int> > &triangle) {
            vector<int> f;
            f.push_back(triangle[0][0]); // initialization
            for (int i = 1; i < triangle.size(); i++) {
                int n = triangle[i].size();
                vector<int> tmp(n);
                // j == 0
                tmp[0] = f[0] + triangle[i][0];
                for (int j = 1; j < n-1; j++) 
                    tmp[j] = min(f[j-1], f[j]) + triangle[i][j];
                // j == len-1
                tmp[n-1] = f[n-2] + triangle[i][n-1]; 

                // refresh
                for (int i = 0; i < n-1; i++)
                    f[i] = tmp[i];
                f.push_back(tmp[n-1]);
            }
            
            int min = f[0];
            for (int i = 1; i < f.size(); i++)
                min = (f[i] < min) ? f[i] : min;

            return min;
        }
};

int main() {
    vector< vector<int> > triangle;
    vector<int> l1; l1.push_back(2);
    vector<int> l2; l2.push_back(3);l2.push_back(4);
    vector<int> l3; l3.push_back(6);l3.push_back(5);l3.push_back(7);
    vector<int> l4; l4.push_back(4);l4.push_back(1);l4.push_back(8);l4.push_back(3);

    triangle.push_back(l1);
    triangle.push_back(l2);
    triangle.push_back(l3);
    triangle.push_back(l4);

    Solution sol;
    cout << sol.minimumTotal(triangle) << endl;
}
