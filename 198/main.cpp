/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> money;

    int helper(vector<int>& nums, int start){
        if(start >= nums.size()) return 0;
        if(money[start] >= 0) return money[start];
        int max_money = 0;
        for(int i = start; i < nums.size(); ++i){
            max_money = max(max_money, helper(nums, i+2)+nums[i]);
        }
        money[start] = max_money;
        return max_money;
    }
    int rob(vector<int>& nums) {
        money.resize(nums.size(), -1);
        return helper(nums, 0);
    }
};
// @lc code=end

