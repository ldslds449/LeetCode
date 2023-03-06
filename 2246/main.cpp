/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

#include <vector>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> degree;
    vector<vector<int>> len;

    int longestPath(vector<int>& parent, string s) {
        const int n = parent.size();
        degree.assign(n, 0);
        len.assign(n, vector<int>(2, 0));

        for(int p : parent){
            if(p >= 0) degree[p]++;
        }

        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(degree[i] == 0) q.push(i);
        }

        int max_len = 0;
        while(!q.empty()){
            int now = q.front(); q.pop();
            max_len = max(max_len, len[now][0] + len[now][1] + 1);
            
            if(now == 0) continue;

            int p = parent[now];
            if(s[now] != s[p]){
                int local_max = max(len[now][0], len[now][1]) + 1;
                if(local_max > len[p][1]) len[p][1] = local_max;
                if(len[p][0] < len[p][1]) swap(len[p][0], len[p][1]);
            }
            if(--degree[p] == 0) q.push(p);
        }

        return max_len;
    }
};
// @lc code=end

