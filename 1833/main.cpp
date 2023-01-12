/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(int i = 0; i < costs.size(); ++i){
            if(coins < costs[i]) break;
            count++;
            coins -= costs[i];
        }
        return count;
    }
};
// @lc code=end

