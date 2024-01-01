/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int> &a, const vector<int> &b){
                return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
            });

        int count = 0;

        set<pair<int,int>> s;
        for(auto &bound : intervals){
            pair<int,int> p = {bound[0], bound[1]};
            auto it = s.upper_bound(p);
            if(it == s.begin()){
                s.insert(p);
            }else{
                it = prev(it);
                if(p.first < it->second){
                    if(p.second < it->second){
                        s.erase(it);
                        s.insert(p);
                    }
                    count++;
                }else{
                    s.insert(p);
                }
            }
        }

        return count;
    }
};
// @lc code=end

