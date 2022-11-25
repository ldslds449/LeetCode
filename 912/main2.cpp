#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void makeHeap(vector<int>& nums){
    for(int i = 1; i < nums.size(); ++i){
      heapify_up(nums, i);
    }
  }

  void heapify_up(vector<int>& nums, int idx){
    while(idx > 0){
      int parent_idx = (idx-1) / 2;
      if(nums[idx] <= nums[parent_idx]) break;
      swap(nums[idx], nums[parent_idx]);
      idx = parent_idx;
    }
  }

  void heapify_down(vector<int>& nums, int idx, int size){
    while(idx < size){
      int child_idx = idx * 2 + 1;
      bool left_larger = false, right_larger = false;
      if(child_idx < size && nums[idx] < nums[child_idx]){
        left_larger = true;
      }
      if(child_idx + 1 < size && nums[idx] < nums[child_idx + 1]){
        right_larger = true;
      }
      if(left_larger && right_larger){
        if(nums[child_idx] > nums[child_idx+1]){
          swap(nums[idx], nums[child_idx]);
          idx = child_idx;
        }else{
          swap(nums[idx], nums[child_idx + 1]);
          idx = child_idx + 1;
        }
      }else if(left_larger){
        swap(nums[idx], nums[child_idx]);
        idx = child_idx;
      }else if(right_larger){
        swap(nums[idx], nums[child_idx + 1]);
        idx = child_idx + 1;
      }else{
        break;
      }
    }
  }

  vector<int> sortArray(vector<int>& nums) {
    makeHeap(nums);
    int size = nums.size();
    for(int i = 0; i < nums.size(); ++i){
      size--;
      // delete
      swap(nums[size], nums[0]);
      // heapify
      heapify_down(nums, 0, size);
    }
    return nums;
  }
};