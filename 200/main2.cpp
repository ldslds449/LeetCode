class Solution {
public:
  void dfs(vector<vector<char>>& grid, int x, int y){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid.front().size()) return;
    if(grid[x][y] != '1') return;
    grid[x][y] = '0';
    dfs(grid, x-1, y);
    dfs(grid, x, y-1);
    dfs(grid, x+1, y);
    dfs(grid, x, y+1);
  }

  int numIslands(vector<vector<char>>& grid) {
    const int M = grid.size();
    const int N = grid.front().size();
    int ans = 0;
    for(int i = 0 ; i < M; ++i){
      for(int j = 0; j < N; ++j){
        if(grid[i][j] == '1'){
          dfs(grid, i, j);
          ans++;
        }
      }
    }
    return ans;
  }
};
