
#include <iostream>
#include <vector>

#include "../leetcode.h"

using namespace std;


ListNode *sortList(ListNode *head)
{

}

int main()
{
    int A[] = {3,1,4,2,5,9,10,6};

    ListNode* p = buildListNode(A, 8);
    ListNode *ans = sortList(p);
    printListNode(ans);
}
