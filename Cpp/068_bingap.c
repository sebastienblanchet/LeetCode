/*
68. Binary Gap
Easy

Given a positive integer N, find and return the longest distance between two 
consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.

Success
Details
Runtime: 4 ms, faster than 84.87% of C online submissions for Binary Gap.
Memory Usage: 6.7 MB, less than 58.46% of C online submissions for Binary Gap.
Next challenges: 
 */

int binaryGap(int N)
{
    int res = 0;
    int count = -32;
    int mask = 1;
    
    while (N)
    {
        printf("N: %i, count: %i, res: %i \n", N, count, res);
        if (N & mask)
        {
            res = res > count ? res : count;
            count = 0;
        }
        
        N >>= 1;
        count++;
    }

    return res;
}



int main(int argc, char const *argv[])
{
    binaryGap(22);
    return 0;
}