/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<unsigned> table(days.size(), 0xFFFFFFFF);

        const int ticket[] = {1, 7, 30};
        int day_idx[] = {-1, -1, -1};

        for(int i = 0; i < days.size(); ++i){
            for(int k = 0; k < 3; ++k){
                unsigned pre_val;
                int target = days[i]-ticket[k];

                if(target <= 0) pre_val = 0;
                else{
                    while(days[day_idx[k]+1] <= target) day_idx[k]++;
                    pre_val = (day_idx[k] < 0 ? 0 : table[day_idx[k]]);
                }

                table[i] = min(table[i], pre_val+costs[k]);
            }
        }
        return table[days.size()-1];
    }
};
// @lc code=end

