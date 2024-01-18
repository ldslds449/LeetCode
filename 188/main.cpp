class Solution {
public:
  int helper(vector<vector<int>> &dp, vector<int> &prices, int t, int i, int k){
    if(i == prices.size() || t == 2*k) return 0;
    if(dp[i][t] != -1) return dp[i][t];

    if(t & 1){ // sell
      dp[i][t] = max(
        prices[i] + helper(dp, prices, t+1, i+1, k)
        helper(dp, prices, t, i+1, k)
      );
    }else{ // buy
      dp[i][t] = max(
        -prices[i] + helper(dp, prices, t+1, i+1, k)
        helper(dp, prices, t, i+1, k)
      );
    }
    return dp[i][t];
  }

  int maxProfit(int k, vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2*k, -1));
    helper(dp, prices, 0, 0, k);
    return dp[prices.size()-1][k*2-1];
  }
};

