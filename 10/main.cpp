class Solution {
public:
  bool helper(string &s, string &p, int s_i, int p_i){
    if(s_i >= s.size() && p_i >= p.size()) return true;
    bool star = p_i+1 < p.size() && p[p_i+1] == '*';
    if(!star){
      if(s_i >= s.size() ^ p_i >= p.size()) return false;
      if(s[s_i] != p[p_i] && p[p_i] != '.') return false;
      return helper(s, p, s_i+1, p_i+1);
    }else{
      while(s_i < s.size()){
        if(s[s_i] != p[p_i] && p[p_i] != '.') break;
        if(helper(s, p, s_i, p_i+2)) return true;
        s_i++;
      }
      if(helper(s, p, s_i, p_i+2)) return true;
      return false;
    }
  }

  bool isMatch(string s, string p) {
    return helper(s, p, 0, 0);
  }
};
