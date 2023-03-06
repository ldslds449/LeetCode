/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects(profits.size());
        for(int i = 0; i < profits.size(); ++i){
          projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> q;

        int i = 0; int idx_i = 0;
        do{
            while(idx_i < projects.size() && projects[idx_i].first <= w){
                q.push(projects[idx_i].second);
                idx_i++;
            }
            if(q.size() == 0) break;
            w += q.top(); q.pop();
            i++;
        }while(i < k);
        return w;
    }
};
// @lc code=end

