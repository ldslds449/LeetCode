#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:

  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    const int N = nums1.size();

    vector<pair<int,int>> nums;
    for(int i = 0; i < N; ++i){
      nums.emplace_back(nums2[i], nums1[i]);
    }
    sort(nums.begin(), nums.end());
    
    long long suffix_sum = 0, ans = -1;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i = N-1; i >= 0; --i){
      suffix_sum += nums[i].second;
      pq.push(nums[i].second);
      if(pq.size() > k){
        suffix_sum -= pq.top();
        pq.pop();
      }
      if(pq.size() == k){
        ans = max(ans, suffix_sum*nums[i].first);
      }
    }

    return ans;
  }
};