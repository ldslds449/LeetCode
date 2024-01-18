class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    auto start_it = upper_bound(intervals.begin(), intervals.end(), newInterval);
    bool start_overlap = 
      start_it != intervals.begin() && 
      (*prev(start_it))[1] >= newInterval[0];
    if(start_overlap) start_it = prev(start_it);

    auto end_it = lower_bound(intervals.begin(), intervals.end(), newInterval, 
                              [](auto &a, auto &b){
                                return a[1] < b[1];
                              });
    bool end_overlap = 
      end_it != intervals.end() &&
      (*end_it)[0] <= newInterval[1];
    if(end_overlap) end_it++;

    if(start_overlap) newInterval[0] = (*start_it)[0];
    if(end_overlap) newInterval[1] = (*prev(end_it))[1];
    int idx = start_it - intervals.begin();

    intervals.erase(start_it, end_it);
    intervals.insert(intervals.begin() + idx, newInterval);
    return intervals;
  }
};

