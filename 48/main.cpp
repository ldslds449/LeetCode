class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    const int M = matrix.size();
    const int N = matrix.front().size();
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < N; ++j){
        if(j < i) continue;
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < N/2; ++j){
        swap(matrix[i][j], matrix[i][N-j-1]);
      }
    }
  }
};
