class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> ans(nums.size());
    int max_val = 0;
    for(int i = 0; i < nums.size(); ++i){
      int &n = nums[i];
      int prev = 0;
      for(int j = i-1; j >= 0; --j){
        if(nums[j] < n){
          prev = max(prev, ans[j]);
        }
      }
      ans[i] = prev + 1;
      max_val = max(max_val, ans[i]);
    }
    return max_val;
  }
};
