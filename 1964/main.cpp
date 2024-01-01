/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lens(obstacles.size());
        vector<int> stack;

        for(int i = 0; i < obstacles.size(); ++i){
            int val = -obstacles[i];
            if(stack.empty() || val <= stack.back()){
                stack.push_back(val);
                lens[i] = stack.size();
            }else{
                auto it = lower_bound(stack.rbegin(), stack.rend(), val);
                *prev(it) = val;
                lens[i] = stack.size()-(it-1-stack.rbegin());
            }
        }

        return lens;
    }
};
// @lc code=end

