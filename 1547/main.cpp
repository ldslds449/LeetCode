/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    map<pair<int,int>, int> dp;

    int helper(vector<int>& cuts, int start, int end, int cut_start, int cut_end){
        if(dp.count({start, end})) return dp[{start, end}];
        if(start == end || cut_start == cut_end) return 0;

        int min_val = INT32_MAX;
        for(int i = cut_start; i < cut_end; ++i){
            int left = helper(cuts, start, cuts[i], cut_start, i);
            int right = helper(cuts, cuts[i], end, i+1, cut_end);
            min_val = min(min_val, left + right);
        }

        int ans = min_val + (end - start);
        dp[{start, end}] = ans;

        return ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return helper(cuts, 0, n, 0, cuts.size());
    }
};
// @lc code=end

