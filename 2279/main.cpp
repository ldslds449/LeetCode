/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i = 0; i < capacity.size(); ++i){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int total = 0, i;
        for(i = 0; i < capacity.size(); ++i){
            if(capacity[i] + total > additionalRocks) break;
            total += capacity[i];
        }
        return i;
    }
};
// @lc code=end

