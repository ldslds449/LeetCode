#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

  bool sum(TreeNode* node, int targetSum){
    if(node == nullptr) return false;
    if(node->left == nullptr && node->right == nullptr){
      return targetSum-node->val == 0;
    }else{
      return sum(node->left, targetSum - node->val) || sum(node->right, targetSum - node->val);
    }
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    return sum(root, targetSum);
  }
};

int main(){
  return 0;
}