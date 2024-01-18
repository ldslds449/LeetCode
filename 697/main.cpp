class Solution {
public:
  class Entry{
  public:
    int cnt;
    int start;
    int end;
    Entry():cnt(0){}
  };

  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, Entry> m;
    for(int i = 0; i < nums.size(); ++i){
      if(m.count(nums[i]) == 0){
        m[nums[i]].start = i;
      }
      m[nums[i]].end = i;
      m[nums[i]].cnt++;
    }
    int max_count = -1, dist = -1;;
    for(auto &[key, val] : m){
      if(max_count < val.cnt){
        max_count = val.cnt;
        dist = val.end - val.start + 1;
      }else if(max_count == val.cnt){
        dist = min(dist, val.end - val.start + 1);
      }
    }
    return dist;
  }
};
