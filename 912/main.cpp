/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int> &arr, int start, int end){
        if(end - start < 2){
            return;
        }

        int mid = (end-start)/2 + start;
        merge(arr, start, mid);
        merge(arr, mid, end);

        vector<int> tmp(arr.begin()+start, arr.begin()+end);
        int l_idx = 0, r_idx = mid-start, idx = start;
        while(true){
            if(l_idx >= mid-start){
                while(r_idx < end-start) arr[idx++] = tmp[r_idx++];
                break;
            }
            if(r_idx >= end-start){
                while(l_idx < mid-start) arr[idx++] = tmp[l_idx++];
                break;
            }
            if(tmp[l_idx] < tmp[r_idx]){
                arr[idx++] = tmp[l_idx++];
            }else{
                arr[idx++] = tmp[r_idx++];
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        merge(nums, 0, nums.size());
        return nums;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> arr{5,1,1,2,0,0};
    s.sortArray(arr);
}
