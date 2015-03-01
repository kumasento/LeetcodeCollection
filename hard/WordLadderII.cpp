
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <unsorted_set>

using namespace std;

void helper(string start, string end,
        unsorted_set<string> &dict, vector<string> &tmp, vector< vector<string> > &ans) {
    if (start == end) {
        tmp.push_back(start);
        ans.push_back(tmp);
        return ;
    }

}

vector< vector<string> > findLadders(string start, string end, unsorted_set<string> &dict) {
    vector< vector<string> > ans;
}

int main() {

    return 0;
}
