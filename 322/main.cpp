/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> cache;

    int helper(vector<int>& coins, int amount){
        if(amount <= 0) return 0;
        if(cache[amount] != -2) return cache[amount];

        int min_val = amount+1;
        for(int c : coins){
            if(c > amount) continue;
            int r = helper(coins, amount - c);
            if(r == -1) continue;
            min_val = min(min_val, r+1);
        }
        min_val = min_val == amount+1 ? -1 : min_val;

        cache[amount] = min_val;

        return min_val;
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        cache.assign(amount+1, -2);

        int r = helper(coins, amount);
        return r > amount ? -1 : r;
    }
};
// @lc code=end

