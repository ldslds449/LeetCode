class Solution {
public:
  int maxProfit(vector<int>& prices) {
    deque<int> dq;
    int ans = 0;
    for(int i = 0; i < prices.size(); ++i){
      if(!dq.empty() && dq.back() > prices[i]){
        ans += dq.back() - dq.front();
        dq.clear();
      }
      dq.push_back(prices[i]);
    }
    ans += (dq.size() > 1 ? dq.back() - dq.front() : 0);
    return ans;
  }
};
