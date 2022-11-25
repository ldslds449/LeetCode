/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        
        vector<int> result;
        for(int i = 0; i < n; ++i){
            int row = 0, col = i;
            while(true){
                if(row == m){
                    result.push_back(col); break;
                }
                int check_col = col + grid[row][col];
                if(check_col >= n || check_col < 0 || 
                    grid[row][check_col] != grid[row][col]){
                    result.push_back(-1); break;
                }
                row++;
                col = check_col;
            }
        }
        return result;
    }
};
// @lc code=end

