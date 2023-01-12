/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

#include <string>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int a[26] = {0};
        for(char c : word1) a[c-'a']++;
        int b[26] = {0};
        for(char c : word2) b[c-'a']++;
        multiset<int> a_set, b_set;
        for(int i = 0; i < 26; ++i){
            if((a[i] > 0) ^ (b[i] > 0)) return false;
            if(a[i] > 0) a_set.insert(a[i]);
            if(b[i] > 0) b_set.insert(b[i]);
        }
        return a_set == b_set;
    }
};
// @lc code=end

