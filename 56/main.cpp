/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> m;
        for(auto &i : intervals){
            m[i[0]]++;
            m[i[1]]--;
        }

        int sum = 0, start;
        vector<vector<int>> ans;
        for(auto &p : m){
            if(sum == 0) start = p.first;
            sum += p.second;
            if(sum == 0) ans.push_back({start, p.first});
        }

        return ans;
    }
};
// @lc code=end

