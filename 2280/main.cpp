/*
 * @lc app=leetcode id=2280 lang=cpp
 *
 * [2280] Minimum Lines to Represent a Line Chart
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(),
          [] (const vector<int> &a, const vector<int> &b)
          {
            return a[0] < b[0];
          });

        int count = 0;
        long long unsigned v1 = 0, v2 = 1;
        for(int i = 1; i < stockPrices.size(); ++i){
            long long unsigned new_v1 = (stockPrices[i][0] - stockPrices[i-1][0]);
            long long unsigned new_v2 = (stockPrices[i][1] - stockPrices[i-1][1]);
            if(new_v1 * v2 != new_v2 * v1){
                count++;
                v1 = new_v1;
                v2 = new_v2;
            }
        }
        return count;
    }
};
// @lc code=end

