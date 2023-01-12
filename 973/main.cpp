/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    void quickSelect(vector<int>& distance, vector<int>& index, int start, int end, int k){
        int pivot = distance[index[start]];
        int left = start;
        int right = end;
        while(true){
            do{ left++; } while(left < end && distance[index[left]] < pivot);
            do{ right--; } while(right >= start && distance[index[right]] > pivot);
            if(left >= right) break;
            swap(index[left], index[right]);
        }
        swap(index[start], index[right]);
        int rank = right - start + 1;
        if(k < rank){
            quickSelect(distance, index, start, right, k);
        }else if(k > rank){
            quickSelect(distance, index, right+1, end, k - rank);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> distance(points.size(), 0);
        vector<int> index(points.size());
        iota(index.begin(), index.end(), 0);
        for(int i = 0; i < points.size(); ++i){
            distance[i] += points[i][0]*points[i][0];
            distance[i] += points[i][1]*points[i][1];
        }
        quickSelect(distance, index, 0, distance.size(), k);
        vector<vector<int>> result;
        for(int i = 0; i < k; ++i){
            result.emplace_back(points[index[i]]);
        }
        return result;
    }
};
// @lc code=end

