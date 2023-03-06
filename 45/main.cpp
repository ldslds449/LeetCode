/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int> q;
        q.push(0);

        int N = nums.size();

        vector<bool> visit(N, false);
        visit[0] = true;

        int step = 0, target = N-1;
        while(true){
            int qsize = q.size();
            while(qsize--){
                int now = q.front(); q.pop();
                if(now == target) return step;
                for(int i = min(N-1, now + nums[now]); i > now; --i){
                    if(visit[i]) continue;
                    q.push(i);
                    visit[i] = true;
                }
            }
            step++;
        }
    }
};
// @lc code=end

