/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int N = satisfaction.size();
        vector<vector<int>> table(N+1, vector<int>(N+1, 0));

        sort(satisfaction.begin(), satisfaction.end());

        for(int i = 1; i <= N; ++i){
            const int sat = satisfaction[i-1];
            for(int k = 1; k < i; ++k){
                table[i][k] = max(table[i-1][k-1] + (sat*k), table[i-1][k]);
            }
            table[i][i] = table[i-1][i-1] + (sat*i);
        }

        return *max_element(table[N].begin(), table[N].end());
    }
};
// @lc code=end

