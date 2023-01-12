/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int helper(vector<int>& prices, vector<int>& profit, int idx){
        if(profit[idx] >= 0) return profit[idx];
        int max_tmp = helper(prices, profit, idx+1);
        for(int j = idx+1; j < prices.size(); ++j){
            int offset = prices[j] - prices[idx];
            if(offset > 0){
                max_tmp = max(max_tmp, offset+profit[j+2]);
            }
        }
        profit[idx] = max_tmp;
        return max_tmp;
    }

    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size()+2, -1);
        profit[prices.size()-1] = profit[prices.size()] = profit[prices.size()+1] = 0;
        return helper(prices, profit, 0);
    }
};
// @lc code=end

