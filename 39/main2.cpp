/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> helper(vector<int>& candidates, int target, int limit){
        if(target == 0) return {{}};
        else if(target < 0) return {};

        vector<vector<int>> all;
        for(int c : candidates){
            if(c > limit) continue;
            auto vec = helper(candidates, target - c, c);
            for(auto &v : vec){
                v.push_back(c);
            }
            all.insert(all.end(), vec.begin(), vec.end());
        }
        return all;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        return helper(candidates, target, target);
    }
};
// @lc code=end

