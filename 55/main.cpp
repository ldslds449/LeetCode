/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        stack<int> s; s.push(0);
        while(!s.empty()){
            int now = s.top(); s.pop();
            if(nums.size()-1-now <= abs(nums[now])) return true;
            for(int i = 1; i <= abs(nums[now]); ++i){
                if(nums[now+i] >= 0){
                    s.push(now+i);
                    nums[now+i] = -nums[now+i];
                }
            }
        }
        return false;
    }
};
// @lc code=end

