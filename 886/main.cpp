/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
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
            bool r = dfs(connect, color, c, !now_color);
            if(!r) return r;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n, -1);
        vector<vector<int>> connect(n);
        for(auto p : dislikes){
            connect[p[0]-1].push_back(p[1]-1);
            connect[p[1]-1].push_back(p[0]-1);
        }

        while(true){
            int idx = -1;
            for(int i = 0; i < n; ++i){
                if(color[i] == -1){
                    idx = i;
                    break;
                }
            }
            if(idx == -1) break;
            bool r = dfs(connect, color, idx, 0);
            if(!r) return false;
        }

        return true;
    }
};
// @lc code=end

