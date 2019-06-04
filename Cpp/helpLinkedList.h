/*
 * 
 * C++ Helper function
 * 
 */

#ifdef __cplusplus
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* vectLL(std::vector<int> inVect){

    // Generate first element
    ListNode *head = new ListNode(inVect[0]);
    ListNode *prev = head;

    std::vector<int>::size_type sz = inVect.size();

    for (unsigned int i = 1; i < sz; i++)
    {
        // std::cout << inVect[i] << std::endl;
        ListNode *cur = new ListNode(inVect[i]);
        prev->next = cur;
        prev = cur;
    }

    return head;
}

int sumLL(ListNode *list){
    
    ListNode *cur = list;

    // Init
    int sum = 0;
    
    while (cur)
    {
        sum += cur->val;
        cur = cur->next;
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


#endif

/*
 * 
 * C Helper function
 * 
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif