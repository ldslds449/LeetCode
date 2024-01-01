class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int x[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int M = board.size();
    const int N = board.front().size();
    vector<vector<int>> new_board(M, vector<int>(N));
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < N; ++j){
        int cnt = 0;
        for(int k = 0; k < 8; ++k){
          int new_x = i + x[k];
          int new_y = j + y[k];
          if(new_x < 0 || new_x >= M || new_y < 0 || new_y >= N) continue;
          cnt += board[new_x][new_y];
        }
        if(board[i][j]){
          if(cnt < 2) new_board[i][j] = 0;
          else if(cnt > 3) new_board[i][j] = 0;
          else new_board[i][j] = 1;
        }else if(cnt == 3){
          new_board[i][j] = 1;
        }
      }
    }
    board = new_board;
  }
};
