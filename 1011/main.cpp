/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

    bool accept(vector<int>& weights, int days, int capacity){
        int d = 0;
        int count = 0;
        for(int &w : weights){
            if(count + w > capacity){
                count = w;
                d++;
                if(d > days) return false;
            }else{
                count += w;
            }
        }
        if(count > 0) d++;
        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, max_val = -1;
        for(int &w : weights){
            sum += w;
            max_val = max(max_val, w);
        }
        
        int start = max_val, end = sum+1;
        while(start < end){
            int mid = (end-start)/2 + start;
            bool ac = accept(weights, days, mid);
            if(ac){
                end = mid;
            }else{
                start = mid+1;
            }
        }

        return start;
    }
};
// @lc code=end

