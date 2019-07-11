/*
137. Single Number II
Medium

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Success
Details
Runtime: 12 ms, faster than 87.82% of C++ online submissions for Single Number II.
Memory Usage: 10.4 MB, less than 8.14% of C++ online submissions for Single Number II.
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        
        for(auto i:nums){
            mp[i]++;
        }
        
        for(auto it:mp){
            if (it.second == 1){
                return it.first;
            }
        }
        
        return 0;
    }
};

