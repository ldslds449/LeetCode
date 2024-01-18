class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for(int i = 0; i < intervals.size(); ++i){
      if(ans.size() == 0) ans.push_back(intervals[i]);
      else{
        int end = ans.back()[1];
        if(intervals[i][0] <= end){
          ans.back()[1] = max(end, intervals[i][1]);
        }else{
          ans.push_back(intervals[i]);
        }
      }
    }
    return ans;
  }
};
