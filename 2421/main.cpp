/*
 * @lc app=leetcode id=2421 lang=cpp
 *
 * [2421] Number of Good Paths
 */

#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int findRoot(vector<int> &parent, int now){
        if(parent[now] == now) return now;
        parent[now] = findRoot(parent, parent[now]);
        return parent[now];
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int,vector<int>> m;
        for(int i = 0; i < vals.size(); ++i){
            m[vals[i]].push_back(i);
        }

        vector<vector<int>> adj(vals.size());
        for(auto &p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<int> parent(vals.size());
        iota(parent.begin(), parent.end(), 0);

        int ans = 0;
        for(auto &p : m){
            int val = p.first;
            for(int &node : p.second){
                for(int &c : adj[node]){
                    if(vals[c] > val) continue;
                    int r1 = findRoot(parent, node);
                    int r2 = findRoot(parent, c);
                    if(r1 != r2){
                        parent[c] = r1;
                        parent[r2] = r1;
                    }
                }
            }
            map<int,int> group;
            for(int &node : p.second) group[findRoot(parent, node)]++;
            for(auto &g : group) ans += (g.second * (g.second-1) / 2) + g.second;
        }

        return ans;
    }
};
// @lc code=end

