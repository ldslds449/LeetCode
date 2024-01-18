class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int &n : nums){
      if(pq.size() < k) pq.push(-n);
      else if(n > -pq.top()){
        pq.pop();
        pq.push(-n);
      }
    }
    return -pq.top();
  }
};
