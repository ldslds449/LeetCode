/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int>& accum, int val){
        int s = 0, e = accum.size();
        while(s < e){
            int mid = (e-s)/2 + s;
            if(accum[mid] <= val){
                s = mid+1;
            }else{
                e = mid;
            }
        }
        return s;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        vector<int> accum(nums.size());
        accum[0] = nums[0];
        for(int i = 1; i < accum.size(); ++i){
            accum[i] = accum[i-1] + nums[i];
        }
        
        for(int &q : queries){
            q = lower_bound(accum, q);
        }
        return queries;
    }
};
// @lc code=end

