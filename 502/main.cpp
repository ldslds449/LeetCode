/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<int> idx(profits.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](const int a, const int b){
            return capital[a] < capital[b];
        });

        auto func = [&](const int a, const int b){
            return profits[a] < profits[b];
        };
        priority_queue<int, vector<int>, function<bool(const int, const int)>> q(func);

        int i = 0; int idx_i = 0;
        do{
            while(idx_i < capital.size() && capital[idx[idx_i]] <= w){
                q.push(idx[idx_i]);
                idx_i++;
            }
            if(q.size() == 0) break;
            w += profits[q.top()]; q.pop();
            i++;
        }while(i < k);
        return w;
    }
};
// @lc code=end

