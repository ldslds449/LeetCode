class Solution {
public:
  int findMin(vector<int>& nums) {
    int start = 0, end = nums.size();
    while(start < end){
      int mid = start + (end - start - 1) / 2;
      if(nums[start] <= nums[end-1]){
        return nums[start];
      }else if(nums[mid] < nums[start]){
        end = mid + 1;
      }else{
        start = mid + 1;
      }
    }
    return nums[start];
  }
};

