/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while(start < end){
            int mid = (end-start)/2 + start;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
};
// @lc code=end

