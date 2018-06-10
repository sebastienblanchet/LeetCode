#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/task-scheduler/discuss/104493/C++-Java-Clean-Code-Priority-Queue

class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        // init a map of characters and count
        unordered_map<char, int> counts;

        // Create a dictionary i.e. key val pair
        for (char t : tasks) {
            cout << "Character: "<< t ;
            counts[t]++;
            cout << " Counter: " << counts[t] <<endl;
        }

        // init queue
        priority_queue< pair<int, char> > pq;

        for (pair<char, int> count : counts) {
            pq.push(make_pair(count.second, count.first));
        }

        int alltime = 0;
        int cycle = n + 1;

        while (!pq.empty()) {
            int time = 0;

            vector< pair<int, char> > tmp;

            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto t : tmp) {
                if (--t.first) {
                    pq.push(t);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};

int main(){

    Solution sl;
    vector<char> tasks;
    tasks.push_back('A');
    tasks.push_back('A');
    tasks.push_back('A');
    tasks.push_back('B');
    tasks.push_back('B');
    tasks.push_back('B');

    cout <<sl.leastInterval(tasks, 2) <<endl;

    return 0;
}
