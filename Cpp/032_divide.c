#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"

/*
Given two integers dividend and divisor, divide 
two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.
 */

int divide(int dividend, int divisor){

    // i.e. is odd
    int quotient = 0;
    // if (divisor < 0 && dividend < 0)
    // {
    //     divisor *= -1;
    //     dividend *= -1;        
    // }
    // else if (divisor < 0){
    //     divisor *= -1;
    //     isNeg = true;
    // }
    // else if (dividend < 0){
    //     dividend *= -1;
    //     isNeg = true;
    // }

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    long dvd = labs(dividend);
    long div = labs(divisor);

    while (dvd >= div) {
        dvd -= div;
        quotient++;
    }

    if (!(dividend < 0 ) != !(divisor < 0)){
        quotient *= -1;
    }

    return quotient;

}


int main(int argc, char const *argv[]){
    /* code */
    printf("%i \n", divide(14, 3));
    printf("%i \n", divide(7, -3));
    printf("%i \n", divide(-7, 3));
    printf("%i \n", divide(-7, -3));

    return 0;
}

