#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution { 
public:
    int lengthOfLastWord(const char *s) {
        int length = 0, backup = 0;
        bool start = false;

        for (int i = 0; i < strlen(s); i++) {
            char c = s[i];

            if (c == ' ') {
                if (start) { start = false; backup = length; length = 0;}
            }
            else {
                if (!start) start = true;
                length ++; 
            }
        }
        if (start) { start = false; backup = length; length = 0;}

        return backup;
    }
};

int main() {
    Solution sol;

    cout << sol.lengthOfLastWord("Hello World") << endl;
    cout << sol.lengthOfLastWord("  ") << endl;
    cout << sol.lengthOfLastWord(" Hello ") << endl;
    cout << sol.lengthOfLastWord("Hello") << endl;
    cout << sol.lengthOfLastWord("H") << endl;

    return 0;
}
