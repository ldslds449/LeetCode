/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size() <= 3) return 0;
        unordered_map<int,unordered_set<int>> tables;
        for(auto &p : points){
            tables[p[0]].insert(p[1]);
        }
        int min_val = 0;
        for(int i = 0; i < points.size(); ++i){
            for(int j = i+1; j < points.size(); ++j){
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
                if(!tables.count(points[i][0]) || !tables.count(points[j][0])) continue;
                if(!tables[points[i][0]].count(points[j][1]) || !tables[points[j][0]].count(points[i][1])) continue;
                int area = abs((points[i][0]-points[j][0])*(points[i][1]-points[j][1]));
                min_val = (min_val == 0 ? area : min(min_val, area));
            }
        }
        return min_val;
    }
};
// @lc code=end

