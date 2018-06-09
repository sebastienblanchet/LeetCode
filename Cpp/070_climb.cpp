#include <iostream>
#include <vector>
#include "Ref/seb_util.c"

using namespace std;

class Solution {
public:
    /* BRUTE FORCE
    int climbStairs(int n) {
      return recurs(0, n);
    }

    int recurs(int i, int n){
        // if i is passed end of stairs endl
        if(i > n){return 0;}
        // if you are at the end
        if(i == n){return 1;}
        // otherwise keep recursing
        return recurs(i+1, n) + recurs(i+2, n);

    }
    BAD BAD
    TIME:   O(2^n)
    SPACE:  O(n)
    */

    /*
    RECURSIVE SOLN w/ MEMORIZATION
    TIME:   O(n)
    SPACE:  O(n)

    int climbStairs(int n){
        // create empty vect with n+1 soln
        vector<int> memo(n+1,0);
        return recurs(0, n, memo);
        printvect1d<int>(memo);

    }

    int recurs(int i, int n, vector<int> &memo){
        // same as before
        if(i > n){return 0;}
        if(i == n){return 1;}
        if(memo[i] > 0){return memo[i];}
        memo[i] = recurs(i+1, n, memo) + recurs(i+2, n, memo);
        return memo[i];
    }
    */

    /*
    DP
    TIME:   O(n)
    SPACE:  O(n)
    */

    int climbStairs(int n){
        if(n==1){return 1;}
        // Init solution
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i <=n; ++i){
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }

};


// Driver program
int main(){
    // init
    Solution soln;
    cout << soln.climbStairs(1000) << endl;
    return 0;
}
