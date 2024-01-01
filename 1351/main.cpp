/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        int x = n-1;
        int y = 0;
        int ans = 0;
        while(x >= 0 && y < m){
            if(grid[y][x] < 0){
                x--;
                ans += m-y;
            }else{
                y++;
            }
        }
        return ans;
    }
};
// @lc code=end

