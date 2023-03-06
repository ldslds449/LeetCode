#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &child, vector<int>& nums, int now, vector<int> &path){
      if(path.size() > 1) ans.emplace_back(path);
      for(int &c : child[now]){
        path.push_back(nums[c]);
        dfs(child, nums, c, path);
        path.pop_back();
      }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
      unordered_map<int,int> prev, first;
      vector<vector<int>> child(nums.size());

      for(int i = 0; i < nums.size(); ++i){
        int start = prev.count(nums[i]) ? prev[nums[i]] : 0;
        for(int k = start; k < i; ++k){
          if(nums[k] <= nums[i]){
            child[k].push_back(i);
          }
        }
        if(prev.count(nums[i]) == 0) first[nums[i]] = i;
        prev[nums[i]] = i;
      }

      for(int i = 0; i < nums.size(); ++i){
        if(first[nums[i]] != i) continue;
        vector<int> path(1, nums[i]);
        dfs(child, nums, i, path);
      }

      return ans;
    }
};