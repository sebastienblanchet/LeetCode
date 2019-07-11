/*
49. Group Anagrams
Medium

Given an array of strings, group anagrams together.
Success
Details
Runtime: 48 ms, faster than 60.76% of C++ online submissions for Group Anagrams.
Memory Usage: 21.3 MB, less than 22.45% of C++ online submissions for Group Anagrams.
Next challenges: 
 */
#include "helper.h"

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        
        // Init answer
        std::vector<std::vector<std::string>> ans({});
        
        // Base case
        if (strs.empty()){
            return ans;
        }

        // Create a KV pair
        std::unordered_map<std::string, std::vector<int>> mp;
        std::string tmp;

        // Iterate through each str and sort each
        // O(n)
        for (int i = 0; i < strs.size(); ++i){

            // Get current str and sort
            tmp = strs[i];

            // O(mlogm) where m is sizeof strs
            sort(tmp.begin(), tmp.end());
            
            // Access key and append index
            mp[tmp].push_back(i);
        }

        // printMapVect<std::string, int>(mp);

        // Build answer vector
        // iterate through map items
        for (auto it:mp){
            // iterate through vect of map item
            std::vector<int> cur = it.second;
            // define temp vector
            std::vector<std::string> v;
            for (auto j:cur){
                // Build temp vector
                v.push_back(strs[j]);
            }

            // Append result to answer
            ans.push_back(v);
        }
        
        return ans;
    }
};

int main(){
    // Driver
    std::vector<std::string> test{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> ans = Solution().groupAnagrams(test);
    printvect2d<std::string>(ans);
    return 0;
}