/*
43. Multiply Strings
Medium

Given two non-negative integers num1 and num2
represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
*/
#include <iostream>
// http://www.cplusplus.com/reference/string/string/
#include <string>

// https://leetcode.com/problems/multiply-strings/discuss/17646/Brief-C%2B%2B-solution-using-only-strings-and-without-reversal
std::string multiply(std::string num1, std::string num2) {
        
    // Get string lengths
    int n1 = num1.size();
    int n2 = num2.size();

    // Init ans of both string size of 0
    std::string ans(n1 + n2, '0');

    // Start at end of both numbers
    for (int i = n1 - 1; 0 <= i; --i){
        int carry = 0;
        for (int j = n2 - 1; 0 <= j; --j){
            int a = (ans[i + j + 1] - '0');
            int b = (num1[i] - '0');
            int c = (num2[j] - '0');
            int temp = a + (b * c) + carry;


            std::cout<< a <<"\n";
            std::cout<< b <<"\n";
            std::cout<< c <<"\n";
            std::cout<< temp <<"\n";
            std::cout<< temp % 10 + '0' <<"\n";
            
            ans[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        // add carry
        ans[i] += carry;

        std::cout<<ans<< "\n";
    }

    // Find position of first non zero
    size_t nonZero = ans.find_first_not_of('0');

    // If found
    if (std::string::npos != nonZero){
        // Go to nonZero
        return ans.substr(nonZero);
    }

    return "0";
}


int main(int argc, char const *argv[])
{
    std::cout << multiply("10", "3") << "\n";
    return 0;
}