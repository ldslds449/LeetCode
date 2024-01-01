class Solution {
public:
  int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<int> presum(arr.size()+1, 0);
    for(int i = 0; i < arr.size(); ++i){
      presum[i+1] = presum[i] + arr[i];
    }
    int start = 0;
    int end = upper_bound(presum.begin(), presum.end(), target) - presum.begin();
    int ans = target + 1;
    while(start < end){
      int mid = start + (end - start) / 2;
      int after = arr.size() - mid;
      int diff = target - presum[mid];
      int avg = arr.back();
      if(after != 0){
        avg = diff / after;
        if(diff % after > after / 2) avg++;
      }
      int limit2 = (mid >= arr.size() ? 999999999 : arr[mid]);
      int limit1 = (mid == 0 ? -1 : arr[mid-1]);
      if(avg >= limit2){
        start = mid + 1;
      }else if(avg < limit1){
        end = mid;
      }else{
        ans = min(avg, ans);
        end = mid;
      }
    }
    return ans;
  }
};

