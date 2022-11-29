/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> table;
        for(auto m : matches){
            table[m[0]] = table[m[0]];
            table[m[1]] = table[m[1]] + 1;
        }
        vector<int> no, one;
        for(auto p : table){
            if(p.second == 0) no.emplace_back(p.first);
            else if(p.second == 1) one.emplace_back(p.first);
        }
        return {no, one};
    }
};
// @lc code=end

