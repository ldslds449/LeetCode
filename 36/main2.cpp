class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
      bool seen[9] = {};
      for(int j = 0; j < 9; ++j){
        if(board[i][j] == '.') continue;
        if(seen[board[i][j]-'1']) return false;
        seen[board[i][j]-'1'] = true;
      }
    }
    for(int i = 0; i < 9; i++){
      bool seen[9] = {};
      for(int j = 0; j < 9; ++j){
        if(board[j][i] == '.') continue;
        if(seen[board[j][i]-'1']) return false;
        seen[board[j][i]-'1'] = true;
      }
    }
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        int centerX = i*3+1, centerY = j*3+1;
        bool seen[9] = {};
        for(int m = -1; m <= 1; ++m){
          for(int n = -1; n <= 1; ++n){
            if(board[centerX+m][centerY+n] == '.') continue;
            if(seen[board[centerX+m][centerY+n]-'1']) return false;
            seen[board[centerX+m][centerY+n]-'1'] = true;
          }
        }
      }
    }
    return true;
  }
};

