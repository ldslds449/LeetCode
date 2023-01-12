/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    struct Compare{
        bool operator()(const float &a, const float &b)const{
            if(abs(a-b) > 1e-4){
                return a < b;
            }else{
                return false;
            }
        }
    };
    
    int maxPoints(vector<vector<int>>& points) {
        map<float, map<float, int, Compare>, Compare> lines;
        for(int i = 0; i < points.size(); ++i){
            for(int j = i+1; j < points.size(); ++j){
                int x_offset = (points[j][0]-points[i][0]);
                int y_offset = (points[j][1]-points[i][1]);
                float s = (x_offset == 0 ? 999999 : (float)y_offset / x_offset);
                float y_val = (x_offset == 0 ? (0-points[i][1])/s+points[i][0] : (0-points[i][0])*s+points[i][1]);
                lines[s][y_val]++;
            }
        }
        int max_val = 0;
        for(auto &p : lines){
            auto &m = p.second;
            for(auto &val : m){
                max_val = max(max_val, val.second);
            }
        }

        return (1+sqrt(1+8*max_val))/2;
    }
};
// @lc code=end

