/*
507. Perfect Number
Easy

We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not. 

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perfect Number.
Memory Usage: 8.3 MB, less than 54.26% of C++ online submissions for Perfect Number.
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if (num <= 0){
            return false;
        }
        
        int sum = 0;
        
        for (int i = 1; i * i <= num; ++i){
            
            if (num % i ==  0){
                sum += i;
                if (i * i != num){
                    sum += num / i;
                }
            }
        }
        
        return (sum - num ) == num;
    }
};