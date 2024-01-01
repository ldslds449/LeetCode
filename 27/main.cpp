class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int idx = 0;
    for(int i = 0, offset = nums.size()-1; i < nums.size(); ++i){
      if(nums[idx] == val){
        swap(nums[idx], nums[offset--]);
      }else{
        idx++;
      }
    }
    return idx;
  }
};

