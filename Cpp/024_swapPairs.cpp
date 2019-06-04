#include "helpLinkedList.h"

// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019/7-8-lines-C%2B%2B-Python-Ruby
ListNode* swapPairs(ListNode* head) {
    ListNode **cur = &head, *a, *b;
    while ((a = *cur) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *cur = b;
        cur = &(a->next);
    }
    return head;
}

int main(int argc, char const *argv[]) {
    std::vector<int> list{1, 2, 3, 4};
    ListNode *ll = vectLL(list);
    printLL(ll);
    printLL(swapPairs(ll));
    return 0;
}