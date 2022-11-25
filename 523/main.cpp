/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 1; i < nums.size(); ++i){
            nums[i] = nums[i-1] + nums[i];
        }
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i){
            nums[i] = nums[i] % k;
            if(nums[i] == 0 && i > 0) return true;
            if(m.count(nums[i])){
                if((i - m[nums[i]]) > 1) return true;
            }else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end

