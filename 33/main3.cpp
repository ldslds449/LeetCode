class Solution {
public:
  int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size()-1;
    while(start <= end){
      int mid = start + (end-start+1)/2;
      if(nums[mid] == target){
        return mid;
      }else if(nums[start] <= nums[end]){
        if(target < nums[mid]){
          end = mid - 1;
        }else{
          start = mid + 1;
        }
      }else{
        if(nums[end] < nums[mid]){
          if(target < nums[mid] && target > nums[end]){
            end = mid - 1;
          }else{
            start = mid + 1;
          }
        }else{
          if(target > nums[mid] && target < nums[start]){
            start = mid + 1;
          }else{
            end = mid - 1;
          }
        }
      }
    }
    return -1;
  }
};
