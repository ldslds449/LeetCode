/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> arr(plantTime.size());
        for(int i = 0; i < plantTime.size(); ++i){
            arr[i] = i;
        }
        sort(arr.begin(), arr.end(), [&](int a, int b){
            return growTime[a] < growTime[b];
        });
        int max_val = 0, pre_sum = 0;
        for(int i = 0; i < plantTime.size(); ++i){
            pre_sum += plantTime[arr[i]];
            max_val = max(max_val, pre_sum+growTime[arr[i]]);
        }
        return max_val;
    }
};
// @lc code=end

