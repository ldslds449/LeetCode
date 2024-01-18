class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,vector<int>> m;
    int total = 0;
    m[0].push_back(-1);
    for(int i = 0; i < nums.size(); ++i){
      total += nums[i];
      m[total].push_back(i);
    }
    int ans = 0;
    for(auto it = m.begin(); it != m.end(); it++){
      int target = it->first + k;
      if(m.count(target)){
        int idx_a = 0, idx_b = 0;
        vector<int> &vec_a = it->second;
        vector<int> &vec_b = m[target];
        for(idx_a = 0; idx_a < vec_a.size() && idx_b < vec_b.size(); idx_a++){
          while(idx_b < vec_b.size() && vec_a[idx_a] >= vec_b[idx_b]) idx_b++;
          ans += vec_b.size() - idx_b;
        }
      }
    }
    return ans;
  }
};
