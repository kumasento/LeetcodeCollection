
#include <iostream>
#include <vector>
#include <queue>

#include "../leetcode.h"

using namespace std;

struct Item
{
    int val, idx;
    Item(int v, int i): val(v), idx(i) {}
    friend bool operator < (Item a, Item b) { return a.val > b.val; }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<Item> q;

    // Initialize
    int n = lists.size();
    for (int i = 0; i < n; i++)
        if (lists[i] != NULL)
            q.push(Item(lists[i]->val, i));

    ListNode *head = new ListNode(0);
    ListNode *tmp = head;
    while (!q.empty())
    {
        Item item = q.top();
        q.pop();

        int idx = item.idx;

        tmp->next = lists[idx];
        tmp = tmp->next;

        lists[idx] = lists[idx]->next;
        if (lists[idx] == NULL)
            continue;

        q.push(Item(lists[idx]->val, idx));
    }

    return head->next;
}

int main()
{
    int A[] = {1,3,5,7};
    int B[] = {2,4,6,8};
    int C[] = {9, 10};

    ListNode *lA = buildListNode(A, 4);
    ListNode *lB = buildListNode(B, 4);
    ListNode *lC = buildListNode(C, 2);

    vector<ListNode*> lists;
    lists.push_back(lA);
    lists.push_back(lB);
    lists.push_back(lC);

    printListNode(mergeKLists(lists));

    return 0;
}
