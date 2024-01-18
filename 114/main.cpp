/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void flatten(TreeNode* root) {
    TreeNode* ans = root;
    stack<TreeNode*> st;
    st.push(root);
    while(st.size() > 0){
      TreeNode* now = st.top(); st.pop();
      if(now == nullptr) continue;
      st.push(now->right);
      st.push(now->left);
      ans->right = now;
      ans->left = nullptr;
      ans = now;
    }
    if(ans != nullptr) ans->right = nullptr;
  }
};
