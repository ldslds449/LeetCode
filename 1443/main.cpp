/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int ans = 0;

    bool dfs(int now, vector<vector<int>>& graph, vector<bool>& hasApple, vector<bool>& seen){
        bool found = hasApple[now];
        seen[now] = true;
        for(int i : graph[now]){
            if(seen[i]) continue;
            bool tmp = dfs(i, graph, hasApple, seen);
            if(tmp) ans++;
            found |= tmp;
        }

        return found;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> seen(n, false);
        dfs(0, graph, hasApple, seen);
        return ans << 1;
    }
};
// @lc code=end

