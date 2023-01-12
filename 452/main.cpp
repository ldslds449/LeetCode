/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto &a, auto &b){
            return a[0] < b[0];
        });
        
        int idx = 0, count = 0;
        while(idx < points.size()){
            int less_end = points[idx][1];
            idx++;
            while(idx < points.size() && points[idx][0] <= less_end){
                less_end = min(less_end, points[idx][1]);
                idx++;
            };
            count++;
        }

        return count;
    }
};
// @lc code=end

