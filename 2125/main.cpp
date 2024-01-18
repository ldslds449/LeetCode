class Solution {
public:
  int numberOfBeams(vector<string>& bank) {
    int prev = 0, ans = 0;
    for(string &s : bank){
      int cnt = 0;
      for(char &c : s){
        cnt += c-'0';
      }
      if(cnt == 0) continue;
      ans += prev * cnt;
      prev = cnt;
    }
    return ans;
  }
};
