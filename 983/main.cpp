/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<unsigned> table(366, 0xFFFFFFFF);
        table[0] = 0;

        const int ticket[] = {1, 7, 30};

        int day_idx = 0;
        int max_day = days.back();
        for(int i = 1; i <= max_day; ++i){
            if(i < days[day_idx]){
                table[i] = table[i-1];
            }else{
                for(int k = 0; k < 3; ++k){
                    int pre = max(i-ticket[k], 0);
                    table[i] = min(table[i], table[pre]+costs[k]);
                }
                day_idx++;
            }
        }
        return table[max_day];
    }
};
// @lc code=end

