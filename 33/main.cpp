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
                bool rotate = nums[start] > nums[end];
                if(rotate){
                    if(nums[mid] >= nums[start]){
                        if(nums[mid] > target){
                            if(target >= nums[start]) end = mid-1;
                            else start = mid+1;
                        }else{
                            start = mid+1;
                        }
                    }else{
                        if(nums[mid] > target){
                            end = mid-1;
                        }else{
                            if(target <= nums[end]) start = mid+1;
                            else end = mid-1;
                        }
                    }
                }else{
                    if(nums[mid] > target){
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

