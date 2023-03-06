/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = (end - start + 1) / 2 + start;
            if(nums[mid] == target) return mid;
            else{
                if(nums[start] > nums[mid]){
                    if(nums[mid] < target && target <= nums[end]){
                        start = mid+1;
                    }else{
                        end = mid-1;
                    }
                }else{
                    if(nums[start] <= target && target < nums[mid]){
                        end = mid-1;
                    }else{
                        start = mid+1;
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end

