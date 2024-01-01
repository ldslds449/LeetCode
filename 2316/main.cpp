/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int dfs(int i, vector<vector<int>> &adj, vector<bool> &visit){
        if(visit[i]) return 0;
        visit[i] = true;
        int count = 1;
        for(auto &c : adj[i]){
            count += dfs(c, adj, visit);
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long total = (long long)n*((long long)n-1)/2;

        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visit(n, false);

        for(int i = 0; i < n; ++i){
            long long count = dfs(i, adj, visit);
            total -= count*(count-1)/2;
        }

        return total;
    }
};
// @lc code=end

