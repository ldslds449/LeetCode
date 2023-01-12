/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for(int i = 0; i < gas.size(); ++i){
            gas[i] -= cost[i];
            total += gas[i];
        }
        if(total < 0) return -1;
        if(gas.size() == 1) return 0;
        
        int front = 0, end = 1, sum = gas[0];
        while(front != end){
            if(sum >= 0){
                sum += gas[end];
                end++;
                if(end == gas.size()) end = 0;
            }else{
                front--;
                if(front < 0) front += gas.size();
                sum += gas[front];
            }
        }
        return end;
    }
};
// @lc code=end

