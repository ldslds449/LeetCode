class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> fail(s.size(), false);
    stack<pair<int,int>> st;
    st.push({0, 1});
    while(!st.empty()){
      auto now = st.top(); st.pop();
      if(now.first == s.size()) return true;
      for(int i = now.second; i <= s.size(); ++i){
        if(fail[i]) continue;
        if(words.count(string(s.begin()+now.first, s.begin()+i))){
          st.push({now.first, i+1});
          st.push({i, i+1});
        }
      }
      fail[now.first] = true;
    }
    return false;
  }
};
