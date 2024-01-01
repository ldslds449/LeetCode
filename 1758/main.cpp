class Solution {
public:
  int minOperations(string s) {
    bool now = false;
    int cnt = 0;
    for(auto &c : s){
      if(now && c != '1' || !now && c != '0') cnt++;
      now = !now;
    }
    return min(cnt, (int)s.size() - cnt);
  }
};
