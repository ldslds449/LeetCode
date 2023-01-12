/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen;
        int max_len = 0, start = 0;
        for(int i = 0; i < s.size(); ++i){
            if(seen.count(s[i]) && seen[s[i]] >= start){
                start = seen[s[i]]+1;
            }
            seen[s[i]] = i;
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};
// @lc code=end

