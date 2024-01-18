class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> tails(nums.size(), 0);
    int size = 0;

    for(int n : nums){
      int start = 0, end = size;
      while(start < end){
        int mid = (end - start) / 2 + start;
        if(tails[mid] < n){
          start = mid + 1;
        }else{
          end = mid;
        }
      }
      tails[start] = n;
      size = max(start+1, size);
    }

    return size;
  }
};
