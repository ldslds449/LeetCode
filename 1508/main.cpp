class Solution {
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    const int mod = (int)(1e9 + 7);
    vector<int> presum(n + 1, 0);
    for(int i = 0; i < n; ++i){
      presum[i+1] = presum[i] + nums[i];
    }
    vector<int> all(n * (n + 1) / 2, 0); int idx = 0;
    for(int i = 0; i < n; ++i){
      for(int j = i + 1; j <= n; ++j){
        all[idx] = presum[j] - presum[i];
        idx++;
      }
    }
    sort(all.begin(), all.end());
    int ans = 0;
    for(int i = left - 1; i < right; ++i){
      ans += all[i];
      ans = ans % mod;
    }
    return ans;
  }
};
