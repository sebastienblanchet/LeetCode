#include <iostream>
#include <vector>
#include <bitset>
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
        int sum = 0;
        int i = 0;

        // use exclusive OR
        // while(i < nums.size()){
        //     sum = sum ^ nums[i];
        //     cout << "Current SUM is " << sum << endl;
        //     i++;
        // }

        // use exclusive OR
        for(i = 0; i < nums.size(); ++i){
            // cout << "SUM in b "<< bitset<3>(sum).to_string() << endl;
            // cout << "NUMS[i] in b "<< bitset<3>(nums[i]).to_string() << endl;
            cout << sum << " XOR " << nums[i];
            sum = sum ^ nums[i];
            cout << " SUM is " << sum << endl;
        }
        return sum;
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
    cout << "Solution is:\n"<< soln.singleNumber(nums) << endl;
    return 0;
}
