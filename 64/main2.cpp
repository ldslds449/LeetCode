/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <vector>
#include <queue>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>> pq;
        const int M = grid.size();
        const int N = grid.front().size();
        vector<vector<bool>> visit(M, vector<bool>(N, false));

        pq.push({-grid[0][0], {0,0}}); visit[0][0] = true;
        while(!pq.empty()){
            auto now = pq.top(); pq.pop();
            int &cost = now.first;
            int &row = now.second.first, &col = now.second.second;
            if(row == M-1 && col == N-1) return -cost;
            if(row+1 < M && !visit[row+1][col]){
                pq.push({cost-grid[row+1][col], {row+1,col}});
                visit[row+1][col] = true;
            }
            if(col+1 < N && !visit[row][col+1]){
                pq.push({cost-grid[row][col+1], {row,col+1}});
                visit[row][col+1] = true;
            }
        }
        return -1;
    }
};
// @lc code=end

