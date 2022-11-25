/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

// @lc code=start

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<pair<int,int>, pair_hash> visit;
        queue<pair<int,int>> q;

        q.push({0, 0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.first == targetCapacity || p.second == targetCapacity || (p.first + p.second) == targetCapacity) return true;
            if(visit.count(p)) continue;
            visit.insert(p);
            if(p.first > 0){
                q.push({0, p.second});
                q.push({
                    max(0, p.first + p.second - jug2Capacity),
                    min(jug2Capacity, p.first + p.second)
                });
            }else{
                q.push({jug1Capacity, p.second});
            }
            if(p.second > 0){
                q.push({p.first, 0});
                q.push({
                    min(jug1Capacity, p.first + p.second),
                    max(0, p.first + p.second - jug1Capacity)
                });
            }else{
                q.push({p.first, jug2Capacity});
            }
        }
        return false;
    }
};
// @lc code=end

