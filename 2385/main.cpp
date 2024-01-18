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
  int child_h = 0;
  int ans = 0;

  int helper(TreeNode* root, int &start, int level){
    if(root == nullptr) return 0;
    int left = helper(root->left, start, level+1);
    int right = helper(root->right, start, level+1);
    if(root->val == start){
      child_h = max(left, right);
      return -1;
    }else if(left < 0 || right < 0){
      ans = max(ans, abs(left) + abs(right));
      return min(left, right) - 1;
    }
    return max(left, right) + 1;
  }

  int amountOfTime(TreeNode* root, int start) {
    helper(root, start, 0);
    return max(child_h, ans);
  }
};

