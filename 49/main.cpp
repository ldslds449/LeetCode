/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(int i = 0; i < strs.size(); ++i){
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(tmp);
        }
        vector<vector<string>> result;
        for(auto &vec : m){
            result.push_back(vec.second);
        }
        return result;
    }
};
// @lc code=end

