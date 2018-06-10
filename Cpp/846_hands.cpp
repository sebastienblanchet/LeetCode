/*
846 Hands of Straights
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group
 is size W, and consists of W consecutive cards.

Return true if and only if she can.



Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

MAP
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        // init empty map of integers
        map<int, int> count;
        // cycle through all cards in hand
        for(int i : hand){
            cout << i << endl;
            //  check if current card is no in map
            if(!count.count(i)){
                // put it in and set count to one?
                count.insert(i, 1);
            }
            else{
                count.swap(i, count.find(i) +1);
            }
        }

        return true;
    }
};


int main(){
    // init
    Solution sln;
    vector<int> hand;
    hand.push_back(1);
    hand.push_back(2);
    hand.push_back(3);
    hand.push_back(6);
    hand.push_back(2);
    hand.push_back(3);
    hand.push_back(4);
    hand.push_back(7);
    hand.push_back(8);

    cout << sln.isNStraightHand(hand, 3) << endl;
    return 0;
}
