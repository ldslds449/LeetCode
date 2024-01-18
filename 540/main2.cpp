class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int start = 0, end = nums.size()/2+1;
    while(start < end){
      int mid = start + (end-start)/2;
      if((mid<<1)+1 < nums.size() && nums[mid<<1] == nums[(mid<<1)+1]){
        start = mid + 1;
      }else{
        end = mid;
      }
    }
    return nums[start<<1];
  }
};
