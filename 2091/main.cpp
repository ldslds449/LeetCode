/*
 * @lc app=leetcode id=2091 lang=cpp
 *
 * [2091] Removing Minimum and Maximum From Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx = 0, max_idx = 0;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[min_idx] > nums[i]) min_idx = i;
            if(nums[max_idx] < nums[i]) max_idx = i;
        }

        int front = min(min_idx, max_idx);
        int rear = max(min_idx, max_idx);
        int min_del = min(rear+1, (int)nums.size()-front);
        min_del = min(min_del, front+1+(int)nums.size()-rear);

        return min_del;
    }
};
// @lc code=end

