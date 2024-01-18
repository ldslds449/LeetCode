class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    map<int,int> m;
    for(int i = 0; i < intervals.size(); ++i){
      m[intervals[i][0]] += 1;
      m[intervals[i][1]] -= 1;
    }
    
    vector<vector<int>> ans;
    int count = 0, start = 0;
    for(auto it = m.begin(); it != m.end(); ++it){
      if(count == 0) start = it->first;
      count += it->second;
      if(count == 0){
        ans.push_back({start, it->first});
      }
    }

    return ans;
  }
};
