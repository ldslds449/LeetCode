/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> judge(n, true);
        vector<int> trusted(n, n-1);
        for(auto vec : trust){
            judge[vec[0]-1] = false;
            trusted[vec[1]-1]--;
        }
        // find 
        for(int i = 0; i < n; ++i){
            if(judge[i] && trusted[i] == 0) return i+1;
        }
        return -1;
    }
};
// @lc code=end

