/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> visited;

    bool dfs(vector<vector<int>>& adj, int source, int destination){
        if(destination == source) return true;
        if(visited[source]) return false;
        visited[source] = true;
        for(int i = 0; i < adj[source].size(); ++i){
            if(dfs(adj, adj[source][i], destination)) return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj, source, destination);
    }
};
// @lc code=end

