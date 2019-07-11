/*

32. Longest Valid Parentheses
Hard

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Runtime: 4 ms, faster than 98.86% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 9.7 MB, less than 54.64% of C++ online submissions for Longest Valid Parentheses.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        // Init
        int ans = 0, res = 0;
        stack<int> arr;
        
        // Itterate through string
        for (int i = 0; i < s.length(); ++i){
            
            // opening bracket, push current result to top of stack
            if (s[i] == '('){
                arr.push(res+2);
                res = 0;
            }
            // Otherwise closing bracket
            else{
                // Check if empty
                if (arr.empty()){
                    res = 0;
                    continue;
                }
                // Access last value
                res += arr.top();
                arr.pop();
                // get max
                ans = max(ans, res);
            }
        }
        
        return ans;
    }
};