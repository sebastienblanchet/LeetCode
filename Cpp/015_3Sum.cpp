/*
015 3Sum LEETCODE
https://leetcode.com/problems/3sum/description/

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Reference
// https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments


// 123ms 51%
vector< vector<int> > threeSum(vector<int> &nums) {

    vector< vector<int> > ans;

    // sort array
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // cycle through items in array
    for (int i = 0; i < n; i++){

        // result of equn : -nums[i] = nums[l] + nums[r]
        int tgt = -nums[i];

        //  right next i
        int l = i + 1;
        int r = n - 1;

          // do until l pointer is at r
          while(l < r){

              int zero = nums[l] + nums[r];

              //  if the RHS less than the LHS
              //  increment left pointer
              if(zero < tgt){
                  l++;
              }
              // otherwise LHS is greater than RHS
              // decrement right pointer
              else if (zero > tgt){
                  r--;
              }
              // otherwise it is equal to zero so add it to solution
              else{
                  // create sub vector in list
                  // create empty vector of len 0
                  vector<int> sub_ans(3,0);
                  sub_ans[0] = nums[i];
                  sub_ans[1] = nums[l];
                  sub_ans[2] = nums[r];
                  ans.push_back(sub_ans);

                  while(l < r &&  nums[l] == sub_ans[1]){
                      l++;

                  }

                  while(l < r &&  nums[r] == sub_ans[1]){
                      r--;
                  }


              }

              // Deal w/ duplicates of [a0, ..]
              while (i < nums.size() - 1 && nums [i+1] == nums[i]){
                  i++;
              }
          }

    }

    return ans;

}

// given idx, element and length print [a_0, ... , a_n-1]
void brackets(int i, int el, int n){
      if(i==0){
          cout <<"[" << el << ", ";

      }
      else if (i == n - 1){
          cout << el << "]";
      }

      else{
          cout << el << ", ";
      }
}

// 1D vect
void printvect1d(vector<int> &vectin){
    for(int i = 0; i < vectin.size(); ++i){
        brackets(i, vectin[i], vectin.size());
    }
}

// 2D vect
void printvect2d(vector< vector<int> > &vectin){
  for(int i = 0; i < vectin.size(); ++i){
      for( int j = 0; j < vectin[i].size(); ++j){
          brackets(j, vectin[i][j], vectin[i].size());
      }
      // brackets(i, vectin[i], vectin.size());
  }
}

// Driver
int main(){

    // init vector
    vector<int> nums;
    nums.push_back(-4);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    //  need to user DOUBLE QUOTES FOR STRINGS OTHERWISE
    // THEY ARE CHARACTER LITERALS https://stackoverflow.com/questions/9130112/compiler-error-character-constant-too-long-for-its-type-whats-wrong?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
    cout << "Input: ";
    printvect1d(nums);
    cout << endl;

    // vector<int> zeros(5,0);
    // cout << "Test: ";
    // printvect1d(zeros);
    // cout << endl;

    // vector of vectors?
    vector< vector<int> > ans = threeSum(nums);
    cout << "Answer ";
    printvect2d(ans);
    cout << endl;

    return 0;
}
