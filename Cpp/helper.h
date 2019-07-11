/*
 * 
 * C++ Helper function
 * 
 */

#ifdef __cplusplus
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <unordered_map>


// given idx, element and length print [a_0, ... , a_n-1]
template<typename T>
void brackets(int i, T el, int n) {
    // Vector of len 1
    if (i == 0 && i == n - 1) {
        std::cout << "[" << el << "]";

    }
    else if (i == 0) {
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
template<typename T>
void printvect1d(std::vector<T> &vectin) {
    for (int i = 0; i < vectin.size(); ++i) {
        brackets<T>(i, vectin[i], vectin.size());
    }
    std::cout << std::endl;
}

// 2D vect
template<typename T>
void printvect2d(std::vector< std::vector<T> > &vectin) {

    std::cout << "[" << std::endl;
    for (int i = 0; i < vectin.size(); ++i) {
        std::cout << "    ";
        printvect1d<T>(vectin[i]);
    }
    std::cout << "]" << std::endl;
}

template<typename T, typename T2>
void printMapVect(std::unordered_map<T, std::vector<T2>> &mapin){
    std::cout << "{" << std::endl;
    for (auto it : mapin) {
        std::cout << "   " << it.first << ":";
        printvect1d<T2>(it.second);
    }
    std::cout << "}" << std::endl;
}

template<typename T>
std::vector<T> vectorRangeFromEnd(int offset, std::vector<T> vecIn)
{
    typedef typename std::vector<T>::const_iterator iterator;
    iterator first = vecIn.end() - offset;
    iterator last  = vecIn.end();
    std::vector<T> vecOut(first, last);

    return vecOut;
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