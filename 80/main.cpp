class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int loc = 1;
    for(int i = 1, cnt = 1; i < nums.size(); ++i){
      if(nums[i] == nums[loc-1]) cnt++;
      else cnt = 1;
      if(cnt <= 2){
        nums[loc] = nums[i];
        loc++;
      }
    }
    return loc;
  }
};
