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

vector< vector<int> > threeSum(vector<int> &num) {

    vector< vector<int> > ans;

    // sort array
    sort(num.begin(), num.end());

    int n = num.size();

    // cycle through items in array
    for (int i = 0; i < n; i++){

        // result of equn : -num[i] = num[l] + num[r]
        int tgt = -num[i];

        //  right next i
        int l = i + 1;
        int r = n - 1;

          // do until l pointer is at r
          while(l < r){

              int zero = num[l] + num[r];

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
                  sub_ans[0] = num[i];
                  sub_ans[1] = num[l];
                  sub_ans[2] = num[r];
                  ans.push_back(sub_ans)

              }


          }

    }

    return ans;

}

// 1D vect
void printvect1d(vector<int> &vectin){

    for(int i = 0; i < vectin.size(); ++i){

        if(i==0){
            cout <<"[" << vectin[i] << ", ";

        }
        else if (i == vectin.size() - 1){
            cout << vectin[i] << "]";
        }

        else{
            cout << vectin[i] << ", ";
        }
    }
}

// 2D vect
// void printvect2d(vector< vector<int> > &vectin){
//
//   for(int i = 0; i < vectin.size(); ++i){
//       // output width
//       // cout.width(3);
//       // cout <<  vectin[i] << endl;
//
//       switch(i){
//
//           case 0:
//               cout <<"[ " << vect[i] << " ,";
//
//           case vectin.size - 1:
//               cout << vect[i] << " ]" << endl;
//
//           default:
//               cout << vect[i] << " ,";
//
//       }
//
//   }
//
// }

// Driver
int main(){

    // init vector
    vector<int> num;
    num.push_back(-4);
    num.push_back(-1);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);

    //  need to user DOUBLE QUOTES FOR STRINGS OTHERWISE
    // THEY ARE CHARACTER LITERALS https://stackoverflow.com/questions/9130112/compiler-error-character-constant-too-long-for-its-type-whats-wrong?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
    cout << "Input: ";
    printvect1d(num);

    vector<int> zeros(5,0);
    cout << "Test: ";
    printvect1d(zeros);



    // vector of vectors?
    // vector< vector<int> > ans = threeSum(num);
    // cout << "Answer " << endl;
    // printvect2d(ans);

    return 0;
}
