/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<tuple<int,int,bool>, int> table;

    int dfs(vector<int>& piles, int idx, int M, bool turn){
        if(idx == piles.size()) return 0;
        if(table.count({idx, M, turn}) > 0) return table[make_tuple(idx, M, turn)];
        int max_val = -INT32_MAX, preSum = 0;
        int limit = min(idx+2*M, (int)piles.size());
        for(int i = idx; i < limit; ++i){
            preSum += piles[i];
            max_val = max(max_val, 
                -dfs(piles, i+1, max(M, i-idx+1), !turn) + preSum);
        }
        table[make_tuple(idx, M, turn)] = max_val;
        return max_val;
    }

    int stoneGameII(vector<int>& piles) {
        int ans = dfs(piles, 0, 1, true);
        for(int &p : piles){
            ans += p;
        }
        return ans >> 1;
    }
};
// @lc code=end

