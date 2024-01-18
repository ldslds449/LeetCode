class Solution {
public:
  void helper(vector<string> &ans, int left, int right, string s){
    if(left == 0 && right == 0) ans.push_back(s);
    if(left > 0) helper(ans, left-1, right+1, s+"(");
    if(right > 0) helper(ans, left, right-1, s+")");
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helper(ans, n, 0, "");
    return ans;
  }
};
