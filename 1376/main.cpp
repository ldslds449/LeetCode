/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> needTime(n, -1);
        int max_time = 0;
        for(int i = 0; i < n; ++i){
            if(i == headID) continue;
            int parent = i;
            int time = 0;
            while(parent != headID){
                if(needTime[parent] != -1){
                    time += needTime[parent];
                    break;
                }
                parent = manager[parent];
                time += informTime[parent];
            }
            needTime[i] = time;
            max_time = max(max_time, time);
        }
        return max_time;
    }
};
// @lc code=end

