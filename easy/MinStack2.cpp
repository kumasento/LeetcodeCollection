#include <iostream>
#include <stack>
#include <vector>

#define MAX_TEST_NUM 10

using namespace std;

class MinStack {
public:
    stack<int> simpleStack, minStack;
    void push(int x) {
        simpleStack.push(x);
        // -- push(0) push(1) push(0) getMin pop getMin: remember double min 
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }
    void pop() {
        if (!minStack.empty() && minStack.top() == simpleStack.top())
            minStack.pop();
        simpleStack.pop();
    }
    int top() {
        return simpleStack.top();
    }
    int getMin() {
        return minStack.top();
    }

};

int main() {
    MinStack minStack;
    
    int X[MAX_TEST_NUM] = { 11, 24, 10, 6, 2, 80, 3, 4, 19, 45 };
    
    for (int i = 0; i < MAX_TEST_NUM; i++)
        minStack.push(X[i]);

    for (int i = 0; i < MAX_TEST_NUM; i++) {
        cout << minStack.top() << " " << minStack.getMin() << endl;
        minStack.pop();
    }

    return 0;
}
