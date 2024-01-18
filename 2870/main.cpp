class Solution {
public:
  int minOperations(vector<int>& nums) {
    unordered_map<int,int> table;
    for(int &n : nums) table[n]++;
    int ans = 0;
    for(auto e : table){
      if(e.second == 1) return -1;
      ans += (e.second-1)/3 + 1;
    }
    return ans;
  }
};
