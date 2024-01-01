/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid.front().size();
        for(int i = 1; i < M; ++i) grid[i][0] += grid[i-1][0];
        for(int k = 1; k < N; ++k) grid[0][k] += grid[0][k-1];
        for(int i = 1; i < M; ++i){
            for(int k = 1; k < N; ++k){
                int top = (i-1 >= 0 ? grid[i-1][k] : 0);
                int left = (k-1 >= 0 ? grid[i][k-1] : 0);
                grid[i][k] += min(top, left);
            }
        }
        return grid[M-1][N-1];
    }
};
// @lc code=end

