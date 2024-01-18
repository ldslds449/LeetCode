class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    vector<int> presum(nums.size()+1, 0);
    for(int i = 0; i < nums.size(); ++i){
      presum[i+1] += presum[i] + nums[i];
    }
    int ans = nums.size()+1;
    for(int i = 1; i <= nums.size(); ++i){ // end
      if(presum[i] < target) continue;
      // decide start idx
      int a = 1, b = i+1;
      while(a < b){
        int mid = a+(b-a)/2;
        int sum = presum[i]-presum[mid-1];
        if(sum >= target){
          a = mid + 1;
          ans = min(ans, i-mid+1);
        }else{
          b = mid;
        }
      }
    }
    return ans == nums.size()+1 ? 0 : ans;
  }
};
