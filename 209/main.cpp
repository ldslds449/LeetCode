class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int total = 0, start = 0, ans = nums.size()+1;
    for(int i = 0; i < nums.size(); ++i){
      total += nums[i];
      while(total - nums[start] >= target){
        total -= nums[start];
        start++;
      }
      if(total >= target) ans = min(ans, i-start+1);
    }
    return ans == nums.size()+1 ? 0 : ans;
  }
};
