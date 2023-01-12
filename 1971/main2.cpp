/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int root(vector<int> &table, int idx){
        if(table[idx] == idx) return idx;
        table[idx] = root(table, table[idx]);
        return table[idx];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> table(n), size(n, 1);
        iota(table.begin(), table.end(), 0);
        for(auto &p : edges){
            int p0_root = root(table, p[0]);
            int p1_root = root(table, p[1]);
            
            if(p0_root != p1_root){
                if(size[p0_root] < size[p1_root]){
                    swap(p0_root, p1_root);
                }

                table[p1_root] = p0_root;
                table[p[0]] = p0_root;
                table[p[1]] = p0_root;
                size[p0_root] += size[p1_root];
            }
        }
        return root(table, source) == root(table, destination);
    }
};
// @lc code=end

