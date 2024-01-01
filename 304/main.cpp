class NumMatrix {
public:
  vector<vector<int>> left;

  NumMatrix(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix.front().size();
    left.resize(M, vector<int>(N, 0));
    left[0][0] = matrix[0][0];
    for(int i = 1; i < M; ++i) left[i][0] = left[i-1][0] + matrix[i][0];
    for(int i = 1; i < N; ++i) left[0][i] = left[0][i-1] + matrix[0][i];
    for(int i = 1; i < M; ++i){
      for(int j = 1; j < N; ++j){
        left[i][j] = matrix[i][j] + left[i-1][j] + left[i][j-1] - left[i-1][j-1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return left[row2][col2]
      - (col1 > 0 ? left[row2][col1-1] : 0)
      - (row1 > 0 ? left[row1-1][col2] : 0)
      + (row1 > 0 && col1 > 0 ? left[row1-1][col1-1] : 0);
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

