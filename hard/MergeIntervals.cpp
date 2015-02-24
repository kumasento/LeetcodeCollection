
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};
struct SortInterval
{
    int start, end;
    SortInterval() : start(0), end(0) {}
    SortInterval(int s, int e): start(s), end(e) {}
    friend bool operator < (SortInterval a, SortInterval b)
    { return (a.start == b.start) ? (a.end < b.end) : (a.start < b.start); }
};

vector<Interval> merge(vector<Interval> &intervals)
{
    vector<SortInterval> sortIntervals;
    for (int i = 0; i < intervals.size(); i++)
        sortIntervals.push_back(SortInterval(intervals[i].start, intervals[i].end));

    sort(sortIntervals.begin(), sortIntervals.end());

    vector<Interval> ans;
    if (intervals.size() <= 0)
        return ans;
    Interval tmp_intvl(sortIntervals[0].start, sortIntervals[0].end);
    for (int i = 1; i < sortIntervals.size(); i++)
    {
        if (sortIntervals[i].start <= tmp_intvl.end)
            tmp_intvl.end = max(sortIntervals[i].end, tmp_intvl.end);
        else
        {
            ans.push_back(tmp_intvl);
            tmp_intvl.start = sortIntervals[i].start;
            tmp_intvl.end = sortIntervals[i].end;
        }
    }
    ans.push_back(tmp_intvl);
    return ans;
}

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));

    vector<Interval> ans = merge(intervals);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].start << ' ' << ans[i].end << endl;
    return 0;
}
