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
  void helper(TreeNode* node, int level, vector<long long> &total, vector<long long> &count){
    if(node == nullptr) return;
    if(total.size() <= level){
      total.push_back(node->val);
      count.push_back(1);
    }else{
      total[level] += node->val;
      count[level] += 1;
    }
    helper(node->left, level+1, total, count);
    helper(node->right, level+1, total, count);
  }

  vector<double> averageOfLevels(TreeNode* root) {
    vector<long long> total, count;
    helper(root, 0, total, count);
    vector<double> ans(total.size());
    for(int i = 0; i < total.size(); ++i){
      ans[i] = (double)total[i] / count[i];
    }
    return ans;
  }
};
