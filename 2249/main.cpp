/*
 * @lc app=leetcode id=2249 lang=cpp
 *
 * [2249] Count Lattice Points Inside a Circle
 */

#include <vector>
#include <utility>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(auto &c : circles){
            int limit = 0;
            while(limit*limit/2 <= c[2]*c[2]){
                for(int x = 0; x <= limit; ++x){
                    int y = limit - x;
                    if(x*x + y*y > c[2]*c[2]) continue;
                    s.insert({c[0]+x, c[1]+y});
                    s.insert({c[0]+x, c[1]-y});
                    s.insert({c[0]-x, c[1]+y});
                    s.insert({c[0]-x, c[1]-y});
                }
                limit++;
            }
        }
        return s.size();
    }
};
// @lc code=end

