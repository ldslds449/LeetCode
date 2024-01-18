class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<vector<int>>> dp(target+1);
    dp[0].push_back({});
    for(int &c : candidates){
      for(int i = 0; i <= target; ++i){
        if(i < c) continue;
        for(int j = 0; j < dp[i-c].size(); ++j){
          vector<int> tmp = dp[i-c][j];
          tmp.push_back(c);
          dp[i].push_back(tmp);
        }
      }
    }
    return dp[target];
  }
};
