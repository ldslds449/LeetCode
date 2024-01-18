class Solution {
public:
  int minDistance(string word1, string word2) {
    const int M = word1.size();
    const int N = word2.size();
    vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
    for(int i = 0; i <= N; ++i) dp[0][i] = i;
    for(int i = 0; i <= M; ++i) dp[i][0] = i;
    for(int i = 1; i <= M; ++i){
      for(int j = 1; j <= N; ++j){
        if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
      }
    }
    return dp[M][N];
  }
};
