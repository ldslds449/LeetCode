class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    const int M = matrix.size();
    const int N = matrix.front().size();
    const int K = min(M, N);
    vector<vector<int>> table(M, vector<int>(N, 0));
    int ans = 0;
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < N; ++j){
        if(matrix[i][j] == '0') continue;
        int a = (j > 0 ? table[i][j-1] : 0);
        int b = (i > 0 ? table[i-1][j] : 0);
        int c = (i > 0 && j > 0 ? table[i-1][j-1] : 0);
        int min_val = min(a, min(b, c));
        table[i][j] = min_val + 1;
        ans = max(ans, table[i][j]);
      }
    }

    return ans * ans;
  }
};
