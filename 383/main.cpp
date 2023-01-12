/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int seen[26] = {0};
        for(char c : magazine){
            seen[c-'a'] += 1;
        }
        for(char c : ransomNote){
            if(seen[c-'a'] == 0) return false;
            seen[c-'a']--;
        }
        return true;
    }
};
// @lc code=end

