/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isSame(vector<int> &p1, vector<int> &p2){
        return (p1[0] == p2[0]) && (p1[1] == p2[1]);
    }

    bool isBoomerang(vector<vector<int>>& points) {
        if(isSame(points[0], points[1]) ||
            isSame(points[0], points[2]) ||
            isSame(points[1], points[2])) return false;
        return (points[2][0] - points[0][0]) * (points[1][1] - points[0][1]) != (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);
    }
};
// @lc code=end

