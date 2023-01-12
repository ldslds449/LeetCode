/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include <string>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string corr[26];
        set<string> seen;

        string tmp = ""; int idx = 0;
        for(int i = 0; i <= s.size(); ++i){
            if(i == s.size() || s[i] == ' '){
                if(idx >= pattern.size()) return false;
                string &t = corr[pattern[idx]-'a'];

                if(t.size() != 0 && t != tmp) return false;
                else if(t.size() == 0){
                    if(seen.count(tmp)) return false;
                    t = tmp;
                    seen.insert(tmp);
                }
                tmp = "";
                idx++;
            }else{
                tmp += s[i];
            }
        }

        return idx == pattern.size();
    }
};
// @lc code=end

