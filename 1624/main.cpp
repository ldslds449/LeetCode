class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    int table[26] = {0}, ans = -1;
    for(int i = 0; i < s.size(); ++i){
      int idx = s[i]-'a';
      if(table[idx]){
        ans = max(ans, i-table[idx]);
      }else{
        table[idx] = i+1;
      }
    }
    return ans;
  }
};

