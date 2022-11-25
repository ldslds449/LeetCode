/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

#include <vector>
#include <queue>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for(auto v : redEdges) red[v[0]].push_back(v[1]);
        for(auto v : blueEdges) blue[v[0]].push_back(v[1]);
        
        queue<pair<int,int>> q;
        q.push({0, 0});

        int dist = 0;
        vector<int> result(n, -1);
        vector<bool> visit_r(n, false), visit_b(n, false);
        while(true){
            int qSize = q.size();
            if(qSize == 0) break;
            for(int i = 0; i < qSize; ++i){
                auto p = q.front(); q.pop();
                if(p.second == 0 || p.second == 1){
                    if(visit_b[p.first]) continue;
                    if(result[p.first] == -1) result[p.first] = dist;
                    visit_b[p.first] = true;
                    for(int c : blue[p.first]){
                        q.push({c, 2});
                    }
                }
                if(p.second == 0 || p.second == 2){
                    if(visit_r[p.first]) continue;
                    if(result[p.first] == -1) result[p.first] = dist;
                    visit_r[p.first] = true;
                    for(int c : red[p.first]){
                        q.push({c, 1});
                    }
                }
            }
            dist++;
        }

        return result;
    }
};
// @lc code=end

