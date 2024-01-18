class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int M = obstacleGrid.size();
    const int N = obstacleGrid.front().size();
    vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
    dp[0][1] = 1;
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < N; ++j){
        if(obstacleGrid[i][j] == 1) continue;
        dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
      }
    }
    return dp[M][N];
  }
};
