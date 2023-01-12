/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool hasEdge(vector<int> bomb1, vector<int> bomb2){
        long long x = bomb1[0]-bomb2[0];
        long long y = bomb1[1]-bomb2[1];
        return x*x + y*y <= (long long)bomb1[2]*bomb1[2];
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int now){
        visited[now] = true;
        
        int num = 0;
        for(int c : graph[now]){
            if(visited[c]) continue;
            num += dfs(graph, visited, c);
        }

        return num+1;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> graph(bombs.size());
        for(int i = 0; i < bombs.size(); ++i){
            for(int j = 0; j < bombs.size(); ++j){
                if(i == j) continue;
                if(hasEdge(bombs[i], bombs[j])) graph[i].push_back(j);
            }
        }

        int max_val = 0;
        for(int i = 0; i < bombs.size(); ++i){
            vector<bool> visited(bombs.size(), false);
            max_val = max(max_val, dfs(graph, visited, i));
        }
        return max_val;
    }
};
// @lc code=end

