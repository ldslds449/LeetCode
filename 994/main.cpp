/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include <vector>
#include <queue>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid.front().size();

        int count = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(grid[i][j] == 1) count++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        const int x[] = {0, 1, 0, -1};
        const int y[] = {-1, 0, 1, 0};

        int time = 0;
        while(!q.empty() && count > 0){
            time++;
            int q_size = q.size();
            for(int k = 0; k < q_size; ++k){
                auto now = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int new_x = x[i] + now.first;
                    int new_y = y[i] + now.second;
                    if(new_x < 0 || new_x >= M) continue;
                    if(new_y < 0 || new_y >= N) continue;
                    if(grid[new_x][new_y] == 1){
                        grid[new_x][new_y] = 2;
                        count--;
                        q.push({new_x, new_y});
                    }
                }
            }
        }

        return count == 0 ? time : -1;
    }
};
// @lc code=end

