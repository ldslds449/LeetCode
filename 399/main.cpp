/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> visited, string now, string &target, double path){
        if(now == target) return path;

        visited.insert(now);
        for(auto &c : adj[now]){
            if(visited.count(c.first)) continue;
            double tmp = dfs(adj, visited, c.first, target, path*c.second);
            if(tmp != -1.0) return tmp;
        }
        visited.erase(now);


        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < equations.size(); ++i){
            auto &eq = equations[i];
            adj[eq[0]].push_back({eq[1], values[i]});
            adj[eq[1]].push_back({eq[0], 1.0/values[i]});
        }

        vector<double> ans;
        for(int i = 0; i < queries.size(); ++i){
            if(adj.count(queries[i][0]) == 0 || adj.count(queries[i][0]) == 0){
                ans.push_back(-1);
            }else{
                ans.push_back(dfs(adj, {}, queries[i][0], queries[i][1], 1.0));
            }
        }

        return ans;
    }
};
// @lc code=end

