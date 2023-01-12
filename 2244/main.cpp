/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> count;
        for(int t : tasks){
            count[t]++;
        }

        int round = 0;
        for(auto &[key, val] : count){
            if(val == 1) return -1;
            round += (val+2)/3;
        }

        return round;
    }
};
// @lc code=end

