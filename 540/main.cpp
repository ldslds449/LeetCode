/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()/2+1;
        while(start < end){
            int mid = (end - start) / 2 + start;
            int idx = mid*2;
            if(idx+1 < nums.size() && nums[idx] == nums[idx+1]){
                start = mid + 1;
            }else if(idx-1 >= 0 && nums[idx] == nums[idx-1]){
                end = mid;
            }else{
                return nums[idx];
            }
        }
        return -1;
    }
};
// @lc code=end

