/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> child_count;
    vector<vector<int>> adj;
    int total;

    int count(int now, int parent){
        int tmp = 0;
        for(int &c : adj[now]){
            if(c == parent) continue;
            tmp += count(c, now);
        }
        child_count[now] = tmp+1;
        return tmp+1;
    }

    int distance(int now, int level, int parent){
        int tmp = 0;
        for(int &c : adj[now]){
            if(c == parent) continue;
            tmp += distance(c, level+1, now);
        }
        return tmp + level;
    }

    void dfs(int now, int parent, vector<int> &answer){
        if(now != 0){
            answer[now] = answer[parent];
            answer[now] -= child_count[now];
            answer[now] += total - (child_count[now]);
        }
        for(int &c : adj[now]){
            if(c == parent) continue;
            dfs(c, now, answer);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        child_count.resize(n, 0);
        adj.resize(n);
        for(auto &p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        total = count(0, -1);
        vector<int> answer(n);
        answer[0] = distance(0, 0, -1);
        dfs(0, -1, answer);
        return answer;
    }
};
// @lc code=end

