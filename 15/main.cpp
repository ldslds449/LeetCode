/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ){
            if(nums[i] > 0) break;

            int start = i+1, end = nums.size()-1;
            while(start < end){
                if(nums[start] + nums[end] + nums[i] < 0){
                    start++;
                }else if(nums[start] + nums[end] + nums[i] > 0){
                    end--;
                }else{
                    ans.push_back({nums[i], nums[start], nums[end]});
                    do{ start++; } while(start < end && nums[start] == nums[start-1]);
                    do{ end--; } while(start < end && nums[end] == nums[end+1]);
                }
            }

            do{ i++; } while(i < nums.size() && nums[i] == nums[i-1]);
        }

        return ans;
    }
};
// @lc code=end

