/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> G(n);
        for(auto r : roads){
            G[r[0]].insert(r[1]);
            G[r[1]].insert(r[0]);
        }

        int max_val = 0;
        for(int i = 0; i < n; ++i){
            for(int k = i+1; k < n; ++k){
                if(max_val < G[i].size() + G[k].size()){
                    int size = G[i].size() + G[k].size();
                    if(G[k].count(i)) size--;
                    if(size > max_val){
                        max_val = size;
                    }
                }
            }
        }

        return max_val;
    }
};
// @lc code=end

