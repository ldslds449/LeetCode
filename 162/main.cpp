class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int start = 0, end = nums.size();
    while(start < end){
      int mid = start + (end - start) / 2;
      bool left_less = (mid == 0) || (nums[mid] > nums[mid-1]);
      bool right_less = (mid == nums.size()-1) || (nums[mid] > nums[mid+1]);
      if(left_less && right_less) return mid;
      else if(left_less) start = mid + 1;
      else end = mid;
    }
    return -1;
  }
};
