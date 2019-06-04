/*
 * 
 * C++ Helper function
 * 
 */

#ifdef __cplusplus
#include <iostream>
#include <vector>

// given idx, element and length print [a_0, ... , a_n-1]
void brackets(int i, int el, int n) {
    if (i == 0) {
        std::cout << "[" << el << ", ";

    }
    else if (i == n - 1) {
        std::cout << el << "]";
    }

    else {
        std::cout << el << ", ";
    }
}

// 1D vect
void printvect1d(std::vector<int> &vectin) {
    for (int i = 0; i < vectin.size(); ++i) {
        brackets(i, vectin[i], vectin.size());
    }
}

// 2D vect
void printvect2d(std::vector< std::vector<int> > &vectin) {
    for (int i = 0; i < vectin.size(); ++i) {
        for ( int j = 0; j < vectin[i].size(); ++j) {
            brackets(j, vectin[i][j], vectin[i].size());
        }
    }
}

#endif

/*
 * 
 * C Helper function
 * 
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#define CHECK_EQ(a,b) if ((a) != (b)) { \
  printf("Check failed at line %d, %s != %s\n", __LINE__, #a, #b); \
  return 0; \
}

void printBinUint32t(uint32_t num)
{
    uint32_t x = sizeof(uint32_t) * 8;

    printf("0x%8x = 0b", num);
    while (x)
    {
        // print out bit in last pos
        printf("%u", ( ((num) >> (x - 1)) & 1 ) );
        // Go to x - 1th bit
        x--;
    }

    printf("\n");

}

void printBinInt(int num)
{
    int x = sizeof(int) * 8;

    printf("0x%8x = 0b", num);
    while (x)
    {
        // print out bit in last pos
        printf("%u", ( ((num) >> (x - 1)) & 1 ) );
        // Go to x - 1th bit
        x--;
    }

    printf("\n");

}

#ifdef __cplusplus
}
#endif