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

 */

#include <iostream>
#include <cmath>
#include <vector>
#include "helper.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ListNode* genLL(std::vector<int> inVect){

//     // Generate first element
//     ListNode head = ListNode(inVect[0]);
//     ListNode prev = head;

//     std::vector<int>::size_type sz = inVect.size();

//     for (unsigned int i = 1; i < sz; i++)
//     {
//         std::cout << inVect[i] << std::endl;
//         ListNode cur = ListNode(inVect[i]);
//         prev.next = &cur;
//         prev = cur;
//     }

//     return head;
// }

class Solution {
public:
    int genNum(ListNode *list){
        
        ListNode *cur = list;

        // Init
        int sum = 0;
        int counter = 0;
        
        while (cur)
        {
            sum += (cur->val * std::pow(10, counter));
            cur = cur->next;
            counter++;
        }

        return sum;
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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum1 = genNum(l1);
        int sum2 = genNum(l2);
        int sum = sum1 + sum2;
        std::cout << sum << std::endl;

        int rem = sum % 10;
        sum /= 10;

        ListNode* ans = new ListNode(rem);
        ListNode* prev = ans;
        // ListNode cur;

        while (sum)
        {
            rem = sum % 10;
            sum /= 10;
            ListNode* cur = new ListNode(rem);
            prev->next = cur;
            prev = cur;
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    ListNode head = ListNode(1);
    ListNode mid = ListNode(2);
    ListNode end = ListNode(3);
    head.next = &mid;
    mid.next = &end;

    ListNode l1 = head;
    ListNode l2 = head;

    // Generate the lists
    // std::vector<int> vect1 = {1, 2, 3};
    // ListNode l1 = genLL(vect1);

    Solution soln;
    soln.printLL(&l1);
    std::cout << soln.genNum(&l1) <<  std::endl;
    ListNode* l3 = soln.addTwoNumbers(&l1, &l2);
    soln.printLL(l3);
    return 0;
}