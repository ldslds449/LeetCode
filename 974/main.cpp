/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        count[0] = 1;

        int sum = 0;
        for(int &n : nums){
            sum += n;
            sum %= k;
            if(sum < 0) sum += k;
            count[sum]++;
        }

        int ans = 0;
        for(int &c : count){
            ans += (c)*(c-1)/2;
        }

        return ans;
    }
};
// @lc code=end

