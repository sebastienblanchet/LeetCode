#include <iostream>
#include <vector>
#include "Ref/seb_util.c"

using namespace std;

/*
136 https://leetcode.com/problems/single-number/description/

Desc:
Given a non-empty array of integers, every element appears twice except
for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

Tags: Bit manip
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> memo;
        int ans;

        // for O(n)
        for(int i = 0; i <nums.size(); ++i){
            // O(n)
            if(find(memo.begin(), memo.end(), nums[i]) != memo.end()){
                cout << nums[i] <<"is in memo" << endl;
            }

            else{
                memo.push_back(nums[i]);
                cout << nums[i] <<"Not in memo" << endl;
            }
        }
        printvect1d<int>(memo);
        return 0;
    }
};


int main(){

    // init vector
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);

    Solution soln;
    cout << "Solution is: "<< soln.singleNumber(nums) << endl;
    return 0;
}
