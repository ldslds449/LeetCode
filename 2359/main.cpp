/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    bool helper(vector<int>& edges, queue<int> &q, vector<bool> &visit1, vector<bool> &visit2){
        bool meet = false;
        int q_size = q.size();
        for(int i = 0; i < q_size; ++i){
            int now = q.front(); q.pop();
            if(visit2[now]) meet = true;
            visit1[now] = true;
            if(edges[now] != -1 && !visit1[edges[now]]) q.push(edges[now]);
        }
        return meet;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        queue<int> q1, q2;
        q1.push(node1);
        q2.push(node2);

        vector<bool> visit1(edges.size(), false);
        vector<bool> visit2(edges.size(), false);

        while(!q1.empty() || !q2.empty()){
            bool meet = false;
            
            meet |= helper(edges, q1, visit1, visit2);
            meet |= helper(edges, q2, visit2, visit1);

            if(meet){
                for(int i = 0; i < edges.size(); ++i){
                    if(visit1[i] && visit2[i]) return i;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

