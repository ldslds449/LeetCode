class Solution {
public:
  void helper(vector<vector<char>> &board, vector<vector<bool>> &pass, int x, int y) {
    const int M = board.size();
    const int N = board.front().size();
    const int off_x[] = { 0, 1, 0,-1};
    const int off_y[] = {-1, 0, 1, 0};
    queue<pair<int,int>> q;
    q.push({x, y});
    pass[x][y] = true;
    while(!q.empty()){
      auto now = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
        const int new_x = now.first + off_x[i];
        const int new_y = now.second + off_y[i];
        if(new_x < 0 || new_x >= M || new_y < 0 || new_y >= N) continue;
        if(board[new_x][new_y] == 'X') continue;
        if(pass[new_x][new_y]) continue;
        pass[new_x][new_y] = true;
        q.push({new_x, new_y});
      }
    }
    
  }

  void solve(vector<vector<char>>& board) {
    const int M = board.size();
    const int N = board.front().size();
    vector<vector<bool>> pass(M, vector(N, false));
    for(int i = 0; i < M; ++i){
      if(board[i][0] == 'O' && pass[i][0] == false) helper(board, pass, i, 0);
      if(board[i][N-1] == 'O' && pass[i][N-1] == false) helper(board, pass, i, N-1);
    }
    for(int i = 0; i < N; ++i){
      if(board[0][i] == 'O' && pass[0][i] == false) helper(board, pass, 0, i);
      if(board[M-1][i] == 'O' && pass[M-1][i] == false) helper(board, pass, M-1, i);
    }
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < N; ++j){
        if(board[i][j] == 'O' && !pass[i][j]) board[i][j] = 'X';
      }
    }
  }
};
