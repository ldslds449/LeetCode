/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int answer = 0;
    
    void helper(vector<vector<int>>& grid, int x, int y, int remain){
        if(x >= grid.size() || x < 0) return;
        if(y >= grid[0].size() || y < 0) return;

        if(grid[x][y] == 2 && remain == 0){
            answer++;
        }
        if(grid[x][y] != 0) return;

        grid[x][y] = -1;

        const static int x_offset[] = {1, 0, -1, 0};
        const static int y_offset[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; ++i){
            int new_x = x+x_offset[i];
            int new_y = y+y_offset[i];
            helper(grid, new_x, new_y, remain-1);
        }

        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int remain = 0, start_x, start_y;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0) remain++;
                else if(grid[i][j] == 1){
                    start_x = i; start_y = j;
                }
            }
        }

        helper(grid, start_x, start_y, remain);
        return answer;
    }
};
// @lc code=end

