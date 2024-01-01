class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;
    for(int i = (int)s.size()-1, j = (int)g.size()-1; i >= 0 && j >= 0; --i){
      if(s[i] >= g[j]){
        cnt++;
      }else{ 
        i++;
      }
      j--;
    }
    return cnt;
  }
};

