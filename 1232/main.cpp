/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // a(x'-x) = b(y'-y)
        int a = coordinates[1][1] - coordinates[0][1];
        int b = coordinates[1][0] - coordinates[0][0];

        for(int i = 2; i < coordinates.size(); ++i){
            int x = coordinates[i][0] - coordinates[0][0];
            int y = coordinates[i][1] - coordinates[0][1];
            if(a*x != b*y) return false;
        }
        return true;
    }
};
// @lc code=end
