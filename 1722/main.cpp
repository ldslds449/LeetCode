/*
 * @lc app=leetcode id=1722 lang=cpp
 *
 * [1722] Minimize Hamming Distance After Swap Operations
 */

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int diff(vector<int>& source, vector<int>& target, vector<int>& idx){
        unordered_map<int,int> diff_map;
        for(int &i : idx){
            diff_map[source[i]]++;
            diff_map[target[i]]--;
        }
        
        int diff_val = 0;
        for(auto &e : diff_map){
            diff_val += abs(e.second);
        }
        return diff_val >> 1;
    }

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int now, vector<int> &idx){
        visited[now] = true;
        idx.push_back(now);
        for(int &c : adj[now]){
            if(visited[c]) continue;
            dfs(adj, visited, c, idx);
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int N = source.size();
        // adj
        vector<vector<int>> adj(N);
        for(auto &p : allowedSwaps){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        // dfs
        int diff_val = 0;
        vector<bool> visited(N, false);
        for(int i = 0; i < N; ++i){
            if(visited[i]) continue;

            vector<int> cc_idx;
            dfs(adj, visited, i, cc_idx);
            diff_val += diff(source, target, cc_idx);
        }

        return diff_val;
    }
};
// @lc code=end

