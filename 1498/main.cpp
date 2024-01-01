/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

#include <algorithm>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        const int mod = (int)(1e9+7);

        stack<int> add;
        int back = nums.size()-1;
        for(int i = 0; i < nums.size(); ++i){
            if((nums[i]<<1) > target) break;
            while(nums[back] > target - nums[i]){ back--; }
            int dist = back - i;
            add.push(dist);
        }

        int val = 1, count = 0, offset = 0;
        while(!add.empty()){
            while(offset == add.top()){
                count += val;
                count %= mod;
                add.pop();
                if(add.empty()) break;
            }
            val <<= 1;
            val %= mod;
            offset++;
        }

        return count;
    }
};
// @lc code=end

