#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // -- first pass: get the sum of all values and number of nodes
        int sumA = 0, countA = 0;

        for(ListNode* p = headA; p != NULL; p = p->next) {
            sumA += p->val;
            countA ++;
        }
        
        // --second pass: plus 1 to all the B's node;
        for (ListNode* p = headB; p != NULL; p = p->next) 
            p->val ++;

        // --third pass: check A's sum again:
        int sumA2 = 0;
        for (ListNode *p = headA; p != NULL; p = p->next)
            sumA2 += p->val;

        // -- then (sumA2-sumA) is the number of nodes that are same
        int countP = sumA2 - sumA;
        // -- and the node starts at countA-countP;
        //
        for (ListNode *p = headB; p != NULL; p = p->next)
            p->val --;

        ListNode *p = headA;
        int upper = countA - countP;
       
        for (int i = 0; p != NULL && i < upper; i++, p = p->next);
            
        return p; 
    }
};

int main() {
    
    ListNode * mainList = new ListNode(1);
    mainList->next = new ListNode(2);
    mainList->next->next = new ListNode(3);
    mainList->next->next->next = new ListNode(4);
    mainList->next->next->next->next = new ListNode(5);

    ListNode * branchList = new ListNode(-1);
    branchList->next = new ListNode(-2);
    branchList->next->next = mainList->next;

    Solution sol;
    ListNode *p = sol.getIntersectionNode(mainList, branchList);

    while(p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
