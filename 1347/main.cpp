class Solution {
public:
  int minSteps(string s, string t) {
    int count[26] = {};
    for(char &c : t) count[c - 'a']++;
    for(char &c : s) count[c - 'a']--;
    int ans = 0;
    for(int i = 0; i < 26; ++i) if(count[i] < 0) ans += -count[i];
    return ans;
  }
};
