class Solution {
public:
  vector<vector<int>> ans;

  void helper(int start, int n, int k, vector<int> &now){
    if(k == 0){
      ans.push_back(now);
      return;
    }
    for(int i = start; i <= n; ++i){
      now.push_back(i);
      helper(i+1, n, k-1, now);
      now.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp;
    helper(1, n, k, tmp);
    return ans;
  }
};
