class Solution {
public:
  void sortColors(vector<int>& nums) {
    int front = 0, back = nums.size()-1;
    for(int i = 0; i <= back; ++i){
      if(nums[i] == 0) swap(nums[front++], nums[i]);
      else if(nums[i] == 2){
        swap(nums[back--], nums[i]);
        i--;
      }
    }
  }
};
