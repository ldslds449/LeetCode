/*
 * @lc app=leetcode id=1828 lang=cpp
 *
 * [1828] Queries on Number of Points Inside a Circle
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int BS(vector<vector<int>>& points, int start, int end, int target, int axis, bool front){
        while(start < end){
            int mid = (end- start) / 2 + start;
            if(target < points[mid][axis]){
                end = mid;
            }else if(points[mid][axis] < target){
                start = mid + 1;
            }else{
                if(front){
                    end = mid;
                }else{
                    start = mid + 1;
                }
            }
        }
        return start;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<int> counts;
        for(auto &q : queries){
            int left_idx = BS(points, 0, points.size(), q[0]-q[2], 0, true);
            int right_idx = BS(points, left_idx, points.size(), q[0]+q[2], 0, false);
            int count = 0;
            for(int i = left_idx; i < right_idx; ++i){
                int x_offset = q[0] - points[i][0];
                int y_offset = q[1] - points[i][1];
                if(x_offset*x_offset + y_offset*y_offset <= q[2]*q[2]) count++;
            }
            counts.push_back(count);
        }
        return counts;
    }
};
// @lc code=end

