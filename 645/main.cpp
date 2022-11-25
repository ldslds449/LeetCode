/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        int twice;
        for(int i : nums){
            if(visit[i]) twice = i;
            visit[i] = true;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!visit[i]) return {twice, i};
        }
    }
};
// @lc code=end

