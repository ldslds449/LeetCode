/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

#include <vector>
#include <queue>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> stop(n, k+2);
        
        vector<vector<int>> adj(n);
        for(int i = 0; i < flights.size(); ++i){
            adj[flights[i][0]].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        // distance, stop, end

        // add source
        for(int &e : adj[src]){
            q.push({flights[e][2], 1, flights[e][1]});
        }
        stop[src] = 1;

        while(!q.empty()){
            auto now = q.top(); q.pop();
            int now_dist = now[0];
            int now_stop = now[1];
            int end = now[2];

            if(stop[end] < now_stop) continue;
            if(now_stop >= k + 2) continue;

            stop[end] = now_stop;

            if(end == dst) return now_dist;

            for(auto &e : adj[end]){
                q.push({now_dist+flights[e][2], now_stop+1, flights[e][1]});
            }
        }

        return -1;
    }
};
// @lc code=end

