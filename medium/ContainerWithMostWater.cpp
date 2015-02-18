#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height) 
{
    int n = height.size();
    int i = 0, j = n-1;
    int max_water = 0;
    while (i < j) 
    {
        // if a[i] < a[j], then if we minus j, the result couldn't be better
        if (height[i] < height[j]) 
            max_water = max(max_water, height[i] * (j-i)), i ++;
        else 
            max_water = max(max_water, height[j] * (j-i)), j --;
    }
    
    return max_water;
}

int main() 
{
    vector<int> height;
    height.push_back(1);
    height.push_back(2);
    height.push_back(4);
    height.push_back(3);

    cout << maxArea(height) << endl;

    return 0;
}
