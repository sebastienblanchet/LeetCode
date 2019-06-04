/*
 * 1. Two Sum
Easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

#include "helper.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        // init
        std::vector<int> ans = {0, 0};
        size_t n  = nums.size();

        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (nums[i] + nums[j] == target){
                    return ans = {i, j};
                }
            }
        }

        return ans;
    
    }
};

int main(int argc, char const *argv[])
{
    Solution soln;
    std::vector<int> v = {3, 1, 2, 4};
    std::vector<int> ans = soln.twoSum(v, 3);
    printvect1d(ans);

    return 0;
}