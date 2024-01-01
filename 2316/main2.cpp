/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int findRoot(int i, vector<int> &parent){
        if(i == parent[i]) return i;
        return parent[i] = findRoot(parent[i], parent);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long total = (long long)n*((long long)n-1)/2;

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for(auto &e : edges){
            int r1 = findRoot(e[0], parent);
            int r2 = findRoot(e[1], parent);

            if(r1 != r2){ // merge
                parent[r2] = r1;
            }
        }

        vector<int> count(n, 0);
        for(int i = 0; i < n; ++i){
          count[findRoot(i, parent)]++;
        }
        for(int i = 0; i < n; ++i){
          total -= (long long)count[i] * ((long long)count[i]-1) /2;
        }

        return total;
    }
};
// @lc code=end

