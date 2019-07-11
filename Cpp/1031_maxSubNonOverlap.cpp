    /*
1031. Maximum Sum of Two Non-Overlapping Subarrays
Medium

Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
*/
#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
    int maxSumTwoNoOverlap(std::vector<int>& A, int L, int M) {
        
        // Apply Kandanes algo O(n)
        for (auto i : A){
            if (A[i] > 0){
                A[i] += A[i-1];
            }
        }

        // Define maximum
        int ans = A[L + M - 1];
        int Lmax = A[L - 1];
        int Mmax = A[M - 1];
        int cur = 0;

        // Consistently check maximums
        for(int i = L + M;  i < A.size(); ++i){
            
            cur = A[i - L - M];
            Lmax = Lmax > (A[i - M] - cur) ? Lmax : (A[i - M] - cur);
            Mmax = Mmax > (A[i - L] - cur) ? Mmax : (A[i - M] - cur);
            ans = std::max(ans, std::max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));

        }

        return ans;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v = {0,6,5,2,2,5,1,9,4};
    int L = 1, M = 2;
    std::cout << Solution().maxSumTwoNoOverlap(v, L, M) << std::endl;
    return 0;
}