/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int> &a) const {
            return hash<int>{}(a.first) ^ hash<int>{}(a.second);
        }
    };

    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<pair<int,int>, Compare> s;
        for(auto &p : points){
            s.insert({p[0], p[1]});
        }
        double min_val = __DBL_MAX__;
        for(int i = 0; i < points.size(); ++i){
            for(int j = 0; j < points.size(); ++j){
                if(i == j) continue;
                int a_x = points[j][0] - points[i][0];
                int a_y = points[j][1] - points[i][1];
                for(int k = 0; k < points.size(); ++k){
                    if(i == k || j == k) continue;
                    int b_x = points[k][0] - points[i][0];
                    int b_y = points[k][1] - points[i][1];
                    if(a_x*b_x + a_y*b_y != 0) continue;
                    if(s.count({points[i][0]+a_x+b_x, points[i][1]+a_y+b_y})){
                        int edge = a_x*b_y - b_x*a_y;
                        min_val = min(min_val, (double)abs(edge));
                    }
                }
            }
        }
        return min_val == __DBL_MAX__ ? 0 : min_val;
    }
};
// @lc code=end

