class Solution {
public:
  bool isIsomorphic(string s, string t) {
    char table[128] = {0};
    bool used[128] = {0};
    for(int i = 0; i < s.size(); ++i){
      if(table[s[i]] == 0){
        if(used[t[i]]) return false;
        table[s[i]] = t[i];
        used[t[i]] = true;
      }
      else if(table[s[i]] != t[i]) return false;
    }
    return true;
  }
};
