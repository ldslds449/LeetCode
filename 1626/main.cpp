/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        map<int,int> table;

        vector<int> index(scores.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int &a, int &b){
            return ages[a] < ages[b] || (ages[a] == ages[b] && scores[a] < scores[b]);
        });

        for(int idx : index){
            auto tmp = table.upper_bound(scores[idx]);
            int max_val = 0;
            for(auto it = table.begin(); it != tmp; it++){
                max_val = max(max_val, it->second);
            }

            table[scores[idx]] = max_val + scores[idx];
        }

        int max_val = 0;
        for(auto it : table){
            max_val = max(max_val, it.second);
        }

        return max_val;
    }
};
// @lc code=end

