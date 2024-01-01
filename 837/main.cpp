/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1.0;
        queue<double> q; q.push(1);

        double window_sum = 1.0;
        double ans = 0;
        for(int i = 1; i <= n; ++i){
            double val = window_sum/maxPts;
            if(i < k){
                window_sum += val;
                q.push(val);
            }else{
                ans += val;
                q.push(0);
            }
            if(q.size() > maxPts){
              window_sum -= q.front();
              q.pop();
            }
        }

        return ans;
    }
};
// @lc code=end

