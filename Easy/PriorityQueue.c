#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;

struct HeapStruct {
    int Size;
    int Capacity;
    int *Elements;
};

PriorityQueue Initialize(int MaxElements) {
    PriorityQueue H;

    H = malloc(sizeof(struct HeapStruct));

    H->Elements = malloc(sizeof(int) * (MaxElements+1));
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = (int) -1E9;

    return H;
}

int IsFull(PriorityQueue H) { return H->Size == H->Capacity; }

void DoubleSpace(PriorityQueue H) {
    H->Capacity = 2 * H->Capacity;

    int * newSpace = malloc(sizeof(int) * H->Capacity);
    memcpy(newSpace, H->Elements, sizeof(int) * H->Capacity);
    free(H->Elements);

    H->Elements = newSpace;
}

void Insert(int X, PriorityQueue H) {
    int i;

    if (IsFull(H)) 
        DoubleSpace(H);

    for (i = ++H->Size; H->Elements[i/2] > X; i /= 2) 
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

int DeleteMin(PriorityQueue H) {
    int i, Child;
    int MinElement, LastElement;

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size --];

    for (i = 1; i * 2 <= H->Size; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child ++;

        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }

    H->Elements[i] = LastElement;
    return MinElement;
}

int main() {
    PriorityQueue PQ = Initialize(0);

    const int MAX_TEST_NUM = 10;
    int i;
    int X[MAX_TEST_NUM] = {11, 23, 8, 64, 33, 79, 2, 1, 98, 102};

    for (i = 0; i < MAX_TEST_NUM; i++)
        Insert(X[i], PQ);

    for (i = 0; i < MAX_TEST_NUM; i++)
        printf("%d\n", DeleteMin(PQ));

    return 0;
}


