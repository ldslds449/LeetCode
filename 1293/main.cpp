/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.front().size();
        set<tuple<int,int>> s, new_s;
        vector<vector<int>> k_value(m, vector<int>(n, -1));

        int dist = 0;
        s.insert({0,0}); k_value[0][0] = k;
        while(!s.empty()){
            int qSize = s.size();
            for(auto h = s.begin(); h != s.end(); ++h){
                auto [i, j] = *h;
                int now_k = k_value[i][j];
                if(i == m-1 && j == n-1){
                    return dist;
                }
                auto add = [&](int new_i, int new_j, int new_k) -> void {
                    if(new_i < 0 || new_j < 0 || new_i >= m || new_j >= n) return;
                    if(grid[new_i][new_j] == 1) new_k--;
                    if(new_k < 0) return;
                    if(new_k <= k_value[new_i][new_j]) return;
                    new_s.insert({new_i, new_j});
                    k_value[new_i][new_j] = new_k;
                };
                add(i+1, j, now_k);
                add(i, j+1, now_k);
                add(i-1, j, now_k);
                add(i, j-1, now_k);
            }
            dist++;
            s = move(new_s);
        }

        return -1;
    }
};
// @lc code=end

