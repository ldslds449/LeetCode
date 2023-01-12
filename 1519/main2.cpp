/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> ans;

    void helper(int now, int parent, vector<vector<int>>& graph, string &labels, vector<int>& count){

        int previous = count[labels[now]-'a'];
        for(int &c : graph[now]){
            if(c == parent) continue;
            helper(c, now, graph, labels, count);
        }
        count[labels[now]-'a']++;

        ans[now] = count[labels[now]-'a'] - previous;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n, 0);

        vector<vector<int>> graph(n);
        for(auto &p : edges){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        vector<int> count(26, 0);
        helper(0, -1, graph, labels, count);

        return ans;
    }
};
// @lc code=end

