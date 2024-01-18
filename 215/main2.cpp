class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int start = 0, end = nums.size();
    while(start < end){
      int pivot = nums[start];
      int idx = start+1;
      for(int i = start+1; i < end; ++i){
        if(nums[i] >= pivot) swap(nums[i], nums[idx++]);
      }
      int rank = idx-start;
      if(rank == k) return nums[start];
      swap(nums[start], nums[idx-1]);
      if(k < rank) end = idx-1;
      else{ 
        start = idx;
        k -= rank;
      }
    }
    return nums[start];
  }
};
