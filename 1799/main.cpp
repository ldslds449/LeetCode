/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 */

#include <vector>
#include <bitset>

using namespace std;

// @lc code=start
class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    int helper(vector<int>& nums, vector<int>& dp, bitset<14>& encode, int level){
        if(level == 0) return 0;

        long encode_int = encode.to_ulong();
        if(dp[encode_int] != -1) return dp[encode_int];

        int max_val = 0;
        for(int i = 0; i < nums.size(); i++){
            if(encode[i]) continue;
            for(int k = 0; k < nums.size(); ++k){
                if(encode[k]) continue;
                if(i == k) continue;
                bitset<14> new_encode(encode);
                new_encode[i] = new_encode[k] = true;
                int r = helper(nums, dp, new_encode, level-1);
                int g = gcd(nums[i], nums[k]);
                max_val = max(max_val, r + g*level);
            }
        }

        dp[encode_int] = max_val;
        return max_val;
    }

    int maxScore(vector<int>& nums) {
        bitset<14> encode(0);
        vector<int> dp(1 << nums.size(), -1);

        return helper(nums, dp, encode, nums.size()/2);
    }
};
// @lc code=end

 