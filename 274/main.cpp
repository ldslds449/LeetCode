class Solution {
public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int start = 1, end = citations.size()+1, ans = 0;
    while(start < end){
      int mid = start + (end - start) / 2;
      int cnt = citations.size() - (lower_bound(citations.begin(), citations.end(), mid) - citations.begin());
      if(cnt >= mid){
        start = mid + 1;
        ans = max(ans, mid);
      }else if(cnt < mid){
        end = mid;
      }
    }
    return ans;
  }
};
