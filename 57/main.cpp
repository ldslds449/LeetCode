/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto cmp = [&](const vector<int> &a, const int &b)->bool{
            return a[1] < b;
        };

        auto it_front = lower_bound(intervals.begin(), intervals.end(), newInterval[0], cmp);
        if(it_front == intervals.end()){
            intervals.insert(intervals.end(), newInterval);
            return intervals;
        }

        auto it_end = lower_bound(intervals.begin(), intervals.end(), newInterval[1], cmp);

        vector<vector<int>> ans(intervals.begin(), it_front);
        if(it_end == intervals.end() || (*it_end)[0] > newInterval[1]){
            ans.push_back({min(newInterval[0], (*it_front)[0]), newInterval[1]});
            ans.insert(ans.end(), it_end, intervals.end());
        }else{
            ans.push_back({min(newInterval[0], (*it_front)[0]), (*it_end)[1]});
            ans.insert(ans.end(), it_end+1, intervals.end());
        }

        return ans;
    }
};
// @lc code=end

