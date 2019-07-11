/*
9. Palindrome Number
Easy

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 */


/*
Success
Details
Runtime: 24 ms, faster than 77.58% of C++ online submissions for Palindrome Number.
Memory Usage: 8.3 MB, less than 60.49% of C++ online submissions for Palindrome Number.

*/ 


class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0, rem = 0;
        int init = x;
        
        if (x < 0){
            return false;
        }
        
        while (x){
            
            rem = x % 10;
            rev *= 10;
            rev += rem;
            x /= 10;
            
            cout << rev << "\n";
        }
    
        bool ans = (rev == init) ? true : false;
        
        return ans;
    }
};