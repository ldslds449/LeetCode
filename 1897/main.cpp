class Solution {
public:
  bool makeEqual(vector<string>& words) {
    int count[26] = {0};
    for(auto &w: words){
      for(auto &c : w){
        count[c-'a']++;
      }
    }
    for(int i = 0; i < 26; ++i){
      if(count[i] % words.size() > 0) return false;
    }
    return true;
  }
}; 
