/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

#include <vector>
#include <stack>

#define MOD 1000000007

using namespace std;

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;

        int sum = 0;
        for(int i = 0; i <= arr.size(); ++i){
            while(!s.empty() && (i == arr.size() || arr[s.top()] >= arr[i])){
                int mid = s.top(); s.pop();
                int left = (s.empty() ? -1 : s.top());
                int count = ((mid - left) * (i - mid)) % MOD;
                sum += (count * arr[mid]) % MOD;
                sum %= MOD;
            }
            s.push(i);
        }

        return sum;
    }
};
// @lc code=end

