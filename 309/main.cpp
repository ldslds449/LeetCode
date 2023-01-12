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
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size()+2, 0);
        for(int i = prices.size()-1; i >= 0; i--){
            int max_tmp = profit[i+1];
            for(int j = i+1; j < prices.size(); ++j){
                int offset = prices[j] - prices[i];
                if(offset > 0){
                    max_tmp = max(max_tmp, offset+profit[j+2]);
                }
            }
            profit[i] = max_tmp;
        }
        return profit[0];
    }
};
// @lc code=end

