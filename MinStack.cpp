#include <iostream>
#include <stack>
#include <vector>

#define MAX_TEST_NUM 10

using namespace std;

class MinStack {
public:
    MinStack() { Initialize(0); }
    void push(int x) {
        Insert(x);
    }
    void pop() {
        DeleteMin();    
    }
    int top() {
        return Elements[1];
    }
    int getMin() {
        return Elements[1];
    }

private:
    int Size;
    int Capacity;
    int *Elements;

    void Initialize(int MaxElements) {
        Elements = (int*)malloc(sizeof(int) * (MaxElements+1));
        Capacity = MaxElements;
        Size = 0;
        Elements[0] = (int) -1E9;
    }
    int IsFull() { return Size == Capacity; }
    void DoubleSpace() {
        Capacity = 2 * Capacity;

        int * newSpace = (int*)malloc(sizeof(int) * Capacity);
        memcpy(newSpace, Elements, sizeof(int) * Capacity);
        free(Elements);

        Elements = newSpace;
    }
    void Insert(int X) {
        int i;

        if (IsFull()) 
            DoubleSpace();

        for (i = ++Size; Elements[i/2] > X; i /= 2) 
            Elements[i] = Elements[i/2];
        Elements[i] = X;
    }
    int DeleteMin() {
        int i, Child;
        int MinElement, LastElement;

        MinElement = Elements[1];
        LastElement = Elements[Size --];

        for (i = 1; i * 2 <= Size; i = Child) {
            Child = i * 2;
            if (Child != Size && Elements[Child + 1] < Elements[Child])
                Child ++;

            if (LastElement > Elements[Child])
                Elements[i] = Elements[Child];
            else
                break;
        }

        Elements[i] = LastElement;
        return MinElement;
    }
};

int main() {
    MinStack minStack;
    
    int X[MAX_TEST_NUM] = { 11, 24, 10, 6, 2, 80, 3, 4, 19, 45 };
    
    for (int i = 0; i < MAX_TEST_NUM; i++)
        minStack.push(X[i]);

    for (int i = 0; i < MAX_TEST_NUM; i++) {
        cout << minStack.getMin() << endl;
        minStack.pop();
    }

    return 0;
}
