#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    

    return l1;
}

int main() {
    int l1_arr[] = {1, 3, 5, 7, 9};
    int l2_arr[] = {2, 4, 6, 8, 10};
    int len1 = 5;
    int len2 = 5;

    ListNode l1 = ListNode(l1_arr[0]);
    ListNode l2 = ListNode(l2_arr[0]);

    for (int i = 1; i < len1; i++) {

        l1->next = ListNode(l1_arr[i]);
        l1 = l1->next;
    }
    for (int i = 1; i < len2; i++) {
        l2->next = ListNode(l2_arr[i]);
        l2 = l2->next;
    }
    ListNode *mergedList = mergeTwoLists(l1, l2);
    ListNode *ptr = mergedList;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }

    return 0;
}
