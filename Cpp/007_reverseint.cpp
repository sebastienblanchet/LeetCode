/*
 * 7. Reverse Integer
Easy

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range:
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Runtime: 4 ms, faster than 93.52% of C++ online submissions for Reverse Integer.
Memory Usage: 8.5 MB, less than 56.45% of C++ online submissions for Reverse Integer.

 */

#include <iostream>
#include <vector>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        long long cur = x % 10;
        long long ans = cur;
        x /= 10;

        while (x){
            cur = x % 10;
            x /= 10;
            ans *= 10;
            ans += cur;
        }

        if (ans >= INT_MAX || ans <= INT_MIN){
            return 0;
        }

        return ans;
    }
};


int main(int argc, char const *argv[]){

    Solution soln;
    int temp;

    std::vector<int> vect = {123, -1234, 120};
    std::vector<int> ans  = {321, -4321, 21};

    for (int i = 0; i < vect.size(); i++){
        std::cout << "In: " << vect[i] << std::endl;
        temp = soln.reverse(vect[i]);
        std::cout << "Out: " << temp << std::endl;

        if (temp == ans[i]){
            std::cout << "PASS" << std::endl;
        }
        else{
            std::cout << "FAIL" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}