#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/unique-morse-code-words/discuss/120675/C++JavaPython-Easy-and-Concise-Solution
int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> s;
    for (auto word : words) {
        string code;
        for (auto c : word) code += d[c - 'a'];
        s.insert(code);
    }
    return s.size();
}

int main(){



  return 0
}
