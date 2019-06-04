/**
 * Definition for singly-linked list.
2. Add Two Numbers
Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Required:

1. Generate each number (2 * 10^0 + 4 * 10^1 + 3 * 10 ^ 2)

Will not work because of overflow

 */

#include <iostream>
#include <vector>
// #include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* genLL(std::vector<int> inVect){

    // Generate first element
    ListNode *head = new ListNode(inVect[0]);
    ListNode *prev = head;

    std::vector<int>::size_type sz = inVect.size();

    for (unsigned int i = 1; i < sz; i++)
    {
        ListNode *cur = new ListNode(inVect[i]);
        prev->next = cur;
        prev = cur;
    }

    return head;
}

void printLL(ListNode* head){

    std::cout << head->val;

    head = head ->next;

    while (head){

        std::cout << "->" << head->val;
        head = head ->next;
    }

    std::cout << std::endl;
}

class Solution {
public:    
    ListNode* mergeLL(ListNode *l1, ListNode *l2) {

        // https://www.geeksforgeeks.org/merge-two-sorted-lists-place/
        // Base cases
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        // start with the linked list
        // whose head data is the least
        if (l1->val < l2->val) {
            l1->next = mergeLL(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeLL(l1, l2->next);
            return l2;
        }
    }
};

int main(int argc, char const *argv[])
{
    // Generate LL
    std::vector<int> vect1 = {1, 3, 5, 7};
    std::vector<int> vect2 = {2, 4, 6, 8};
    ListNode *l1 = genLL(vect1);
    ListNode *l2 = genLL(vect2);

    // Solution
    Solution soln;
    std::cout << "List1:  ";
    printLL(l1);
    std::cout << "List2:  ";
    printLL(l2);
    std::cout << "Result: ";
    ListNode *l3 = soln.mergeLL(l1, l2);
    printLL(l3);
    return 0;
}