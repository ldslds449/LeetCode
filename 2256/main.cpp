/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = 0;
        for(int i = 0; i < nums.size(); ++i){
            total += nums[i];
        }

        long long min_idx, min_val = total+1, accum = 0;
        for(int i = 0; i < nums.size(); ++i){
            accum += nums[i];
            long long pre = accum/(i+1);
            long long suf = (i == nums.size()-1 ? 0 : (total-accum)/(nums.size()-i-1));
            long long diff = abs(pre-suf);
            if(diff < min_val){
                min_val = diff;
                min_idx = i;
            }
        }

        return min_idx;
    }
};
// @lc code=end

