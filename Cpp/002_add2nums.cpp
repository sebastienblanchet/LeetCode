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
#include <cmath>
#include <vector>
#include "helper.h"

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


    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
        
        ListNode dummy(0);
        ListNode *cur = &dummy;

        int sum = 0;
        
        // Iterate through list
        while (l1 || l2 || sum) {
            
            // Add values from both lists
            // and proceed to next
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }

            // Create new node with digit
            // in ONES column
            cur->next = new ListNode(sum % 10);

            // This is the carry
            sum /= 10;
            
            // Go to next
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> vect1{2,4,3};
    std::vector<int> vect2{5,6,4};
    ListNode *l1 = genLL(vect1);
    ListNode *l2 = genLL(vect2);

    Solution soln;
    std::cout << soln.genNum(l1) <<  std::endl;
    soln.printLL(soln.addTwoNumbers2(l1, l2));
    return 0;
}