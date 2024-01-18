class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> first(matrix.size());
    for(int i = 0; i < matrix.size(); ++i){
      first[matrix.size()-i-1] = -matrix[i].front();
    }

    auto row_it = lower_bound(first.begin(), first.end(), -target);
    if(row_it == first.end()) return false;
    int row_idx = (matrix.size()-1) - (row_it - first.begin());
    
    vector<int> &row = matrix[row_idx];
    auto col_it = lower_bound(row.begin(), row.end(), target);
    if(col_it == row.end()) return false;
    return *col_it == target;
  }
};
