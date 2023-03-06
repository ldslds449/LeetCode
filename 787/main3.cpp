/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);

        vector<vector<int>> adj(n);
        for(int i = 0; i < flights.size(); ++i){
            adj[flights[i][0]].push_back(i);
        }

        queue<pair<int,int>> q;
        q.push({src, 0});

        int step = 0;
        while(!q.empty() && step <= k){
            int qs = q.size();
            while(qs--){
                auto now = q.front(); q.pop();
                for(int &e : adj[now.first]){
                    if(dist[flights[e][1]] < now.second + flights[e][2]) continue;
                    dist[flights[e][1]] = now.second + flights[e][2];
                    q.push({flights[e][1], dist[flights[e][1]]});
                }
            }
            step++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
// @lc code=end

