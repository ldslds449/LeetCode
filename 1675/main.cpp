/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:

    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int min_val = 1000000001;
        for(int &n : nums){
            int el = (n&1) ? (n << 1) : n;
            min_val = min(min_val, el);
            q.push(el);
        }

        int ans = q.top() - min_val;
        while((q.top() & 1) == 0){
            int next = q.top() >> 1;
            q.push(next);
            min_val = min(min_val, next);
            q.pop();
            ans = min(ans, q.top() - min_val);
        }

        return ans;
    }
};
// @lc code=end

