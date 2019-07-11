/*


476. Number Complement
Easy

Given a positive integer, output its complement number.

The complement strategy is to flip the bits of its binary representation.

 */

#include "helper.h"

int findComplement(int num) {
    // mask is 1
    int mask = 0xFFFFFFFF;    
    while(mask & num){
        mask <<= 1;
    }
    printBinInt(mask);
    printBinInt(~num);

    return mask ^ (~num);
}

/*
int firstOne(int num){
    if (num == 0){
        return 0;
    }
    
    // look at first bit
    int mask = 0x80000000;

    while ( !(mask & num) ) {
        num << = 1;
    }
}

int findComplement2(int num){
    return ((~0) << (firstOne(num))) ^ (~num);
}
*/


int main(int argc, char const *argv[])
{
    printBinInt(findComplement2(5));
    // printBinInt(findComplement(5));
    return 0;
}