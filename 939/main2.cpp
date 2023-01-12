/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    struct Hash {
        size_t operator()(const pair<int,int>&x)const{
            return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
        }
    };

    int minAreaRect(vector<vector<int>>& points) {
        if(points.size() <= 3) return 0;

        map<int,vector<int>> table;
        for(auto &p : points){
            table[p[1]].emplace_back(p[0]);
        }

        unordered_map<pair<int,int>, int, Hash> last;
        int min_val = INT_MAX;
        for(auto &p : table){
            auto &vec = p.second;
            sort(vec.begin(), vec.end());
            for(int i = 0; i < vec.size(); ++i){
                for(int j = i+1; j < vec.size(); ++j){
                    int y1 = vec[i], y2 = vec[j];
                    auto it = last.find({y1,y2});
                    if(it != last.end()){
                        min_val = min(min_val, (y2-y1)*(p.first-it->second));
                    }
                    last[{y1,y2}] = p.first;
                }
            }
        }
        
        return min_val == INT_MAX ? 0 : min_val;
    }
};
// @lc code=end

