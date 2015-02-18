
#include <iostream>
#include <vector>

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total = 0;
    int sum = 0;
    int start_idx = -1;

    for (int i = 0; i < gas.size(); i++)
    {
        sum += (gas[i] - cost[i]);
        total += (gas[i] - cost[i]);

        if (sum < 0)
        {
            start_idx = i;
            sum = 0;
        }
    }
    return (total >= 0) ? start_idx + 1 : -1;
}

int main()
{

    return 0;
}
