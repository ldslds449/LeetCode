class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> t;
    int max_len = 0;
    for(auto &n : nums){
      if(t.count(n)){
        continue;
      }else{
        bool prev = t.count(n-1);
        bool next = t.count(n+1);
        if(prev && next){
          int head = t[n-1];
          int tail = t[n+1];
          t[head] = tail;
          t[tail] = head;
          t[n] = 0;
          max_len = max(max_len, tail-head+1);
        }else if(prev){
          int head = t[n-1];
          t[n] = head;
          t[head] = n;
          max_len = max(max_len, n-head+1);
        }else if(next){
          int tail = t[n+1];
          t[n] = tail;
          t[tail] = n;
          max_len = max(max_len, tail-n+1);
        }else{
          t[n] = n;
          max_len = max(max_len, 1);
        }
      }
    }
    return max_len;
  }
};
