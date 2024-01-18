class Solution {
public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    unordered_map<int,int> table;
    vector<vector<int>> ans;
    for(auto &n : nums){
      const int idx = table[n];
      if(idx >= ans.size()){
        ans.push_back({n});
      }else{
        ans[idx].push_back(n);
      }
      table[n]++;
    }
    return ans;
  }
};
