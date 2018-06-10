#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include "Ref/seb_util.c"

using namespace std;

/*
187 sequences
All DNA is composed of a series of nucleotides abbreviated as
A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences
 (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

bit manip, hash table
*/


// https://leetcode.com/problems/repeated-dna-sequences/discuss/53952/20-ms-solution-(C++)-with-explanation
class Solution{
public:
    vector <string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        bitset<1<<20> str1;
        bitset<1<<20> str2;

        //  treat ATCG as bits
        int val = 0;
        // get first 10 letters of sequence
        for(int i = 0; i < 10; ++i){
            // cout << s[i];
            // create 20 bit sequence
            val = (val << 2) | charval(s[i]);
        }

        str1.set(val);
        cout << val << " | ";
        // add two bits to front to determine if it was seen or not
        int mask = (1 <<20) -1;

        for (int i = 10; i <s.size(); i++){

            val = ((val << 2) & mask) | charval(s[i]);
            if (str2[val])
                continue;
            if (str1[val]) {
                ans.push_back(s.substr(i-10+1, 10));
                str2.set(val);
             }
             else
                 str1.set(val);
        }

        return ans;
    }

    int charval(char c){
        switch(c){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return 0;
        }
    }
};



int main(){
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sln;
    vector<string> ans;
    ans = sln.findRepeatedDnaSequences(str);
    printvect1d<string>(ans);
    return 0;
}
