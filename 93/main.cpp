/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int start, string str, int count){
        if(count == 3){
            if(s.size() - start > 3 || s.size() == start) return;
            if(s.size() - start > 1 && s[start] == '0') return;
            int tmp = 0;
            for(int i = start; i < s.size(); ++i){
                tmp *= 10;
                tmp += s[i] - '0';
            }
            if(tmp <= 255) ans.push_back(str + "." + string(s.begin()+start, s.end()));
        }else{
            int end = s[start] == '0' ? start+1 : min((int)s.size(), start+3);
            int tmp = 0;
            for(int i = start; i < end; ++i){
                tmp *= 10;
                tmp += s[i] - '0';
                if(tmp > 255) break;
                string new_str = (str.size() == 0 ? "" : str+".") + string(s.begin()+start, s.begin()+i+1);
                dfs(s, i+1, new_str, count+1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, "", 0);
        return ans;
    }
};
// @lc code=end

