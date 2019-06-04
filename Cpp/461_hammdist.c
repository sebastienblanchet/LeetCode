#include "helper.h"

// Success
// Details
// Runtime: 4 ms, faster than 88.82% of C online submissions for Hamming Distance.
// Memory Usage: 6.7 MB, less than 60.77% of C online submissions for Hamming Distance.
// Next challenges: 

int hammingDistance(int x, int y){
    int ans = 0;
    int mask = 1;
    int n = (x^y);

    printBinInt(x);
    printBinInt(y);
    printBinInt(n);

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

int main(int argc, char const *argv[])
{
    int ans = hammingDistance(1, 3);
    printf("%i", ans);
    return 0;
}