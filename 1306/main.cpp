/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        stack<int> s;
        s.push(start);

        vector<bool> visit(arr.size(), false);

        while(!s.empty()){
            int now = s.top(); s.pop();
            if(now < 0 || now >= arr.size()) continue;
            if(arr[now] == 0) return true;
            if(visit[now]) continue;
            visit[now] = true;
            s.push(now + arr[now]);
            s.push(now - arr[now]);
        }
        return false;
    }
};
// @lc code=end

