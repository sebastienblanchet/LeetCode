#include "helper.h"

class Solution
{
private:
    std::vector<std::string> ans;

public:
    void backtrack(int lb, int rb, std::string str)
    {
        // if you have no brackets left in the stack add to ans
        if (lb == 0 && rb == 0)
        {
            ans.push_back(str);
            return;
        }

        if (lb > 0)
        {
            backtrack(lb - 1, rb, str + "(");
        }

        if (rb > lb)
        {
            backtrack(lb, rb - 1, str + ")");
        }


    }

    std::vector<std::string> generateParenthesis(int n)
    {
        backtrack(n, n, "");
        return ans;
    }
};


int main()
{
    Solution soln;
    int numpars = 3;
    std::vector<std::string> ans;
    ans = soln.generateParenthesis(numpars);
    printvect1d<std::string>(ans);
    return 0;
}

