/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        for(int i = 0; i < temperatures.size(); ++i){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                temperatures[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            temperatures[s.top()] = 0;
            s.pop();
        }
        return temperatures;
    }
};
// @lc code=end

