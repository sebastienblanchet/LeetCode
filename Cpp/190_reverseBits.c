/*
 * Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Bits.
 * Memory Usage: 6.7 MB, less than 9.17% of C online submissions for Reverse Bits.
 *
 */

#include "helper.h"

uint32_t reverseBits(uint32_t n) {

    // Init declartions
    uint32_t ans, mask1, temp, counter;

    // Define mask1 to get first bit
    ans = 0;
    mask1 = 0x80000000;
    temp = 0;
    counter = 0;

    while (n){

        // Extract bit in first position
        temp = n & mask1;
        temp >>= (31 - counter);
        ans |= temp;

        // Left shift 1 n and mask
        n <<= 1;
        counter++;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    // 00000010100101000001111010011100
    uint32_t test = 43261596;
    printBinUint32t(test);

    // 00111001011110000010100101000000
    uint32_t ans = 964176192;
    printBinUint32t(ans);

    uint32_t res = reverseBits(test);
    printBinUint32t(res);

    CHECK_EQ(ans, res);
    
    return 0;
}