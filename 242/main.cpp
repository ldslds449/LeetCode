/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> table(26, 0);
        for(auto c : s){
            table[c-'a']++;
        }
        for(auto c : t){
            table[c-'a']--;
        }
        for(int i = 0; i < 26; ++i){
            if(table[i] != 0) return false;
        }
        return true;
    }
};
// @lc code=end

