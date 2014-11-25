#include <iostream>
#include <vector>
#include <stack>

#include "leetcode.h"

using namespace std;

class Solution {
public:
    stack<ListNode *> nodeStack;
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *tmp;
        int i;

        for (tmp = head; tmp != NULL; tmp = tmp->next) 
            nodeStack.push(tmp);
        for (i = 0; i < n; i++)
            nodeStack.pop();

        if (nodeStack.empty())
            return head->next;
        tmp = nodeStack.top();
        tmp->next = tmp->next->next;

        return head;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution sol;
    ListNode *res = sol.removeNthFromEnd(node1, 5);
    ListNode *tmp;
    for (tmp = res; tmp != NULL; tmp = tmp->next)
        cout << tmp->val << endl;

    return 0;
}
