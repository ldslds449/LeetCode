/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

#include <vector>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int>> &flights, vector<vector<int>> &adj, vector<vector<int>> &cache, int now, int dst, int k){
        if(now == dst) return 0;
        if(!k) return INT_MAX;
        if(cache[now][k] != -1) return cache[now][k];

        int dist = INT_MAX;
        for(int &e : adj[now]){
            int d = dfs(flights, adj, cache, flights[e][1], dst, k-1);
            if(d != INT_MAX){
                dist = min(dist, d + flights[e][2]);
            }
            
        }

        cache[now][k] = dist;
        return dist;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj(n);
        vector<vector<int>> cache(n, vector<int>(k+2, -1));

        for(int i = 0; i < flights.size(); ++i){
            adj[flights[i][0]].push_back(i);
        }

        int d = dfs(flights, adj, cache, src, dst, k+1);
        return d == INT_MAX ? -1 : d;
    }
};
// @lc code=end

