
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int maxL = newInterval.start;
    int maxR = newInterval.end;
    int ns = newInterval.start, ne = newInterval.end;
    vector<Interval> ans;
    int idx = 0, n = intervals.size();
}

int main() {

    return 0;
}
