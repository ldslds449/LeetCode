/*
 * @lc app=leetcode id=1515 lang=cpp
 *
 * [1515] Best Position for a Service Centre
 */

#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    double average(vector<vector<int>>& positions, int axis){
        double total = 0;
        for(auto &point : positions){
            total += point[axis];
        }
        return total / positions.size();
    }

    double dist(vector<vector<int>>& positions, int x, int y){
        double result = 0;
        for(int i = 0; i < positions.size(); ++i){
            int x_offset = positions[i][0] - x;
            int y_offset = positions[i][1] - y;
            result += sqrt(x_offset*x_offset+y_offset*y_offset);
        }
        return result;
    }

    double getMinDistSum(vector<vector<int>>& positions) {
        double x = average(positions, 0);
        double y = average(positions, 1);

        double result = __DBL_MAX__;
        result = min(result, dist(positions, floor(x), floor(y)));
        result = min(result, dist(positions, floor(x), ceil(y)));
        result = min(result, dist(positions, ceil(x), floor(y)));
        result = min(result, dist(positions, ceil(x), ceil(y)));

        return result;
    }
};
// @lc code=end

