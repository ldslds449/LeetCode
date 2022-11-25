/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,int>> q;
        unordered_set<string> visited;
        for(int i = 0; i < graph.size(); ++i){
            q.push({i, (1<<i)});
        }
        const int target = 1 << graph.size();
        int dist = 0;
        while(!q.empty()){
            int qSize = q.size();
            bool found = false;
            for(int i = 0; i < qSize; ++i){
                auto p = q.front(); q.pop();
                if(p.second+1 == target){
                    found = true;
                    break;
                }
                string str = to_string(p.second) + " " + to_string(p.first);
                if(visited.count(str)) continue;
                visited.insert(str);
                for(int c : graph[p.first]){
                    q.push({c, p.second | (1<<c)});
                }
            }
            if(found) break;
            dist++;
        }
        return dist;
    }
};
// @lc code=end

