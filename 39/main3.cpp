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

    void back(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &path, int target, int limit){
        if(target == 0){
            ans.emplace_back(path);
            return;
        }else if(target < 0) return;
        
        for(int c : candidates){
            if(c > limit) break;
            path.push_back(c);
            back(candidates, ans, path, target - c, c);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> path;
        back(candidates, ans, path, target, target);

        return ans;
    }
};
// @lc code=end

