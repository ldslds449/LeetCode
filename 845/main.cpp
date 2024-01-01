/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3) return 0;

        bool valid = false;
        int diff = 0, count = 1;
        int max_count = 0;
        for(int i = 1; i < arr.size(); ++i){
            int new_diff = arr[i] - arr[i-1];
            if(diff > 0 && new_diff > 0 ||
                diff < 0 && new_diff < 0 ||
                diff > 0 && new_diff < 0){
                count++;
            }else if(diff == 0 && new_diff > 0 ||
                diff < 0 && new_diff > 0){
                count = 2;
            }else{
                count = 0;
            }
            if(diff > 0 && new_diff < 0 && valid == false) valid = true;
            else if(valid && new_diff >= 0) valid = false;
            if(valid) max_count = max(max_count, count);
            diff = new_diff;
        }

        return max_count;
    }
};
// @lc code=end

