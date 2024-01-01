/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int max_len = -1;
    int idx = 0;

    void dfs(int now, vector<int>& edges, vector<int> &ing, vector<bool> &visit){
        if(visit[now]) return;
        ing[now] = idx++;
        int next = edges[now];
        if(next != -1){
            if(ing[next] >= 0){
                max_len = max(max_len, idx - ing[next]);
            }else{
                dfs(next, edges, ing, visit);
            }
        }
        ing[now] = -1;
        idx--;
        visit[now] = true;
    }

    int longestCycle(vector<int>& edges) {
        vector<bool> visit(edges.size(), false);
        vector<int> ing(edges.size(), -1);
        stack<int> st;

        for(int i = 0; i < edges.size(); ++i){
            dfs(i, edges, ing, visit);
        }

        return max_len;
    }
};
// @lc code=end

