/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums, int idx){
        if(idx == nums.size()-1){
            ans.emplace_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); ++i){
            swap(nums[idx], nums[i]);
            helper(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};
// @lc code=end

