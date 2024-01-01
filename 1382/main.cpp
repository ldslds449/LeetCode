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
  TreeNode* divide(vector<int> &values, int start, int end){
    if(start >= end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* now = new TreeNode(values[mid]);
    now->left = divide(values, start, mid);
    now->right = divide(values, mid + 1, end);
    return now;
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<int> values;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
      TreeNode* now = st.top();
      st.pop();
      if(now == nullptr) continue;
      values.push_back(now->val);
      st.push(now->left);
      st.push(now->right);
    }

    sort(values.begin(), values.end());
    return divide(values, 0, values.size());
  }
};
