#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Segmentation fault 11 is an infinite loop


class Solution {
private:
    vector<string> ans;

public:
    void backtrack(int lb, int rb, string str){
        // if you have no brackets left in the stack add to ans
        if(lb ==0 && rb ==0){
            ans.push_back(str);
            return;
        }
        if(lb>0){
            backtrack(lb-1, rb, str+"(");
        }
        if(rb>lb){
            backtrack(lb, rb-1, str+")");
        }

    }

    // Backtracking solution https://leetcode.com/problems/generate-parentheses/discuss/10341/Simple-C++-sol-backtracking
    vector<string> generateParenthesis(int n){
        backtrack(n,n,"");
        return ans;
    }

    // https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C++-solution
    /*vector<string> generateParenthesis(int n) {
        vector <string> ans;
        pars(ans, "", n, 0);
        return ans;

    }

    // pass ans vector byref
    void pars(vector<string> &vectin, string sub_ans, int n, int m){

        if(n==0 && m==0){
            vectin.push_back(sub_ans);
            return;
        }

        if(m>0){
            pars(vectin, sub_ans + ")", n, m-1);
        }

        if(n>0){
            pars(vectin, sub_ans + "(", n-1, m+1);
        }

    }
    */
};


// UTILS------------------------------------------------------------
// given idx, element and length print [a_0, ... , a_n-1]
template<typename T>
void brackets(int i, T el, int n){
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
template<typename T>
void printvect1d(vector<T> &vectin){
    for(int i = 0; i < vectin.size(); ++i){
        brackets<T>(i, vectin[i], vectin.size());
    }
    cout << endl;
}


int main(){
    int numpars;
    Solution soln;
    cout << "Enter number of pars" << endl;
    cin >> numpars;
    vector<string> ans;
    ans = soln.generateParenthesis(numpars);
    //  use template
    printvect1d<string>(ans);
    return 0;
}
