#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
    string buf1 = string("");
    string buf2 = string("");

    int n1 = version1.length();
    int n2 = version2.length();

    int p1 = 0, p2 = 0;
    while (p1 < n1 || p2 < n2) {
        for (; p1 < n1 && version1[p1] != '.'; p1 ++)
            buf1.push_back(version1[p1]);
        for (; p2 < n2 && version2[p2] != '.'; p2 ++)
            buf2.push_back(version2[p2]);
        
        int a1 = 0, a2 = 0;
        
        if (buf1.length() != 0) a1 = atoi(buf1.c_str());
        if (buf2.length() != 0) a2 = atoi(buf2.c_str());

        if (a1 > a2) return 1;
        else if (a2 > a1) return -1;

        buf1 = string("");
        buf2 = string("");

        p1 ++;
        p2 ++;
    }
    int a1 = 0, a2 = 0;
    if (buf1.length() != 0) a1 = atoi(buf1.c_str());
    if (buf2.length() != 0) a2 = atoi(buf2.c_str());
    if (a1 > a2) return 1;
    else if (a2 > a1) return -1;

    return 0;
}

int main() {
    /*
    cout << compareVersion(string("1"), string("2")) << endl; 
    cout << compareVersion(string("2"), string("1")) << endl; 
    cout << compareVersion(string("2.1"), string("1.2")) << endl; 
    cout << compareVersion(string("0.2.1"), string("1.2")) << endl; 
    cout << compareVersion(string("0.2.1"), string("0.1.2")) << endl; 
    cout << compareVersion(string("0.2"), string("0.2.2")) << endl; 
    */
    cout << compareVersion(string("1.0"), string("1")) << endl; 

    return 0;
}
