/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> table(target+1);
        table[0].push_back({});

        for(int i = 1; i <= target; ++i){
            for(int c : candidates){
                if(c > i) continue;
                for(auto vec : table[i-c]){
                    bool accept = true;
                    for(int e : vec){
                        if(e > c){
                            accept = false;
                            break;
                        }
                    }
                    if(!accept) continue;
                    vec.push_back(c);
                    table[i].emplace_back(vec);
                }
            }
        }

        return table[target];
    }
};
// @lc code=end

