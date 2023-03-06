/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> count(s.size()+1, 0);
        
        int tmp = 0;
        for(int i = 1; i <= s.size(); ++i){
            if(s[i-1] == '1') tmp++;
            count[i] = tmp;
        }

        tmp = 0;
        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] == '0') tmp++;
            count[i] += tmp;
        }

        int ans = s.size();
        for(int i = 0; i <= s.size(); ++i){
            ans = min(ans, count[i]);
        }

        return ans;
    }
};
// @lc code=end

