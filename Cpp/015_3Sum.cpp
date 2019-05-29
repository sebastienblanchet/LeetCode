/*
015 3Sum LEETCODE
https://leetcode.com/problems/3sum/description/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

// Reference
// https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments

// 123ms 51%
std::vector< std::vector<int> > threeSum(std::vector<int> &nums) {

    std::vector< std::vector<int> > ans;

    // sort array
    std::sort(nums.begin(), nums.end());

    int n = nums.size();

    // cycle through items in array
    for (int i = 0; i < n; i++) {

        // result of equn : -nums[i] = nums[l] + nums[r]
        int tgt = -nums[i];

        //  right next i
        int l = i + 1;
        int r = n - 1;

        // do until l pointer is at r
        while (l < r) {

            int zero = nums[l] + nums[r];

            //  if the RHS less than the LHS
            //  increment left pointer
            if (zero < tgt) {
                l++;
            }
            // otherwise LHS is greater than RHS
            // decrement right pointer
            else if (zero > tgt) {
                r--;
            }
            // otherwise it is equal to zero so add it to solution
            else {
                // create sub vector in list
                // create empty vector of len 0
                std::vector<int> sub_ans(3, 0);
                sub_ans[0] = nums[i];
                sub_ans[1] = nums[l];
                sub_ans[2] = nums[r];
                ans.push_back(sub_ans);

                while (l < r &&  nums[l] == sub_ans[1]) {
                    l++;

                }

                while (l < r &&  nums[r] == sub_ans[1]) {
                    r--;
                }

            }

            // Deal w/ duplicates of [a0, ..]
            while (i < nums.size() - 1 && nums [i + 1] == nums[i]) {
                i++;
            }
        }

    }

    return ans;
}

// Driver
int main() {

    // init vector
    std::vector<int> nums;
    nums.push_back(-4);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    //  need to user DOUBLE QUOTES FOR STRINGS OTHERWISE
    // THEY ARE CHARACTER LITERALS https://stackoverflow.com/questions/9130112/compiler-error-character-constant-too-long-for-its-type-whats-wrong?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
    std::cout << "Input: ";
    printvect1d(nums);
    std::cout << endl;

    // vector of vectors?
    std::vector< std::vector<int> > ans = threeSum(nums);
    std::cout << "Answer ";
    printvect2d(ans);
    std::cout << endl;

    return 0;
}
