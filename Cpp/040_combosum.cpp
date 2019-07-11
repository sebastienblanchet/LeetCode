/*
40. Combination Sum II
Medium

Given a collection of candidate numbers (candidates)
 and a target number (target), find all unique combinations 
 in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.
*/

#include <algorithm>
#include "helper.h"


/*
 Runtime: 8 ms, faster than 96.17% of C++ online submissions for Combination Sum II.
Memory Usage: 9 MB, less than 82.91% of C++ online submissions for Combination Sum II.
 */

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(
        std::vector<int>& candidates, int target) {
        
        // Init ans
        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        // Sort the vector initial
        std::sort(candidates.begin(), candidates.end());

        // Do depth first search
        dfs(candidates, 0, target, path, ans);

        return ans;
        
    }

    void dfs(std::vector<int> &candidates, int cur, int target, 
        std::vector<int> &path, std::vector<std::vector<int>> &ans){

        if (target == 0){
            ans.push_back(path);
            return;
        }

        if (target < 0){
            return;
        }

        for (int i = cur; i <candidates.size(); ++i){
            if (i > cur && candidates[i] == candidates[i - 1]){
                continue;
            }

            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], path, ans);
            path.pop_back();
        }
    }
};


/*
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
 */

int main(int argc, char const *argv[])
{
    Solution soln;

    int target = 8;
    std::vector<int> input = {10,1,2,7,6,1,5};
    std::vector< std::vector<int> > ans = soln.combinationSum2(input, target);
    printvect2d<int>(ans);

    return 0;
}