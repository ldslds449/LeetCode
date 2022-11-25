/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>> &connect, vector<int> &color, int now, int now_color){
        if(color[now] != -1) return color[now] == now_color;
        color[now] = now_color;
        for(int c : connect[now]){
            if(!dfs(connect, color, c, !now_color)) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); ++i){
            if(color[i] == -1 && !dfs(graph, color, i, 0)) return false;
        }

        return true;
    }
};
// @lc code=end

