/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> isRoot(n, true);
        for(int i = 0; i < edges.size(); ++i){
            isRoot[edges[i][1]] = false;
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(isRoot[i]) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

