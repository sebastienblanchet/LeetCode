/*
Given a std::string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <iostream>
#include <vector>
#include <string>
#include "helper.h"

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {

        // Init result
        std::vector<std::string> ans;
        ans.push_back("");
        
        // Define keypad map
        std::string map[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (int i = 0; i < digits.size(); ++i){
            std::vector<std::string> temp;

            // Get ith number of digits and convert to int 
            // to map index
            std::string chars = map[digits[i] - '0'];

            for (int c = 0; c < chars.size(); ++c){
                for (int j = 0; j < ans.size(); ++j){
                    temp.push_back(ans[j] + chars[c]);
                }
                ans = temp;
            }
        }
        
        return ans;       
    }
};


int main(int argc, char const *argv[])
{
    Solution soln;

    std::vector<std::string> ans = soln.letterCombinations("23");
    printvect1d<std::string>(ans);

    return 0;
}