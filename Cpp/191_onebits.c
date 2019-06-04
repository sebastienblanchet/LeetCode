/*
 *Runtime: 4 ms, faster than 92.74% of C++ online submissions for Number of 1 Bits.
Memory Usage: 8.3 MB, less than 6.33% of C++ online submissions for Number of 1 Bits.
 */

#include "helper.h"

int hammingWeight(uint32_t n) {
    int ans = 0;
    uint32_t mask = 0x00000001;

    while (n)
    {
        if (n & mask)
        {
            ans++;
        }
        n >>= 1;
    }

    return ans;
}

int main(int argc, char const *argv[]){

    uint32_t test = 0xFFFFFFFF;
    printBinUint32t(test);

    uint32_t ans = 32;
    printBinUint32t(ans);

    uint32_t res = hammingWeight(test);
    printBinUint32t(res);

    printf("Ans: %i \n", hammingDistance(1, 4));


    return 0;
}