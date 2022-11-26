/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int bs(vector<int>& startTime, vector<int> &arr, int start, int target){
        int end = arr.size();
        while(start < end){
            int mid = (end-start)/2 + start;
            if(startTime[arr[mid]] < target){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return start;
    }

    int dfs(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int> &arr, int idx, vector<int> &cache){
        if(idx >= arr.size()) return 0;
        if(cache[idx] != -1) return cache[idx];
        // get next job index
        int next_idx = bs(startTime, arr, idx+1, endTime[arr[idx]]);
        cache[idx] = max(dfs(startTime, endTime, profit, arr, next_idx, cache) + profit[arr[idx]], 
            dfs(startTime, endTime, profit, arr, idx+1, cache));
        return cache[idx];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // sort
        vector<int> arr(startTime.size());
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), [&](int &a, int &b){
            return (startTime[a] < startTime[b]) ||
                (startTime[a] == startTime[b] && endTime[a] < endTime[b]) ||
                (startTime[a] == startTime[b] && endTime[a] == endTime[b] && profit[a] < profit[b]);
        });
        // recursive
        vector<int> cache(startTime.size(), -1);
        return dfs(startTime, endTime, profit, arr, 0, cache);
    }
};
// @lc code=end

