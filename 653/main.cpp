#include <iostream>
#include <vector>
#include <stack>

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
  bool find(TreeNode* root, int k, TreeNode* skip){
    if(root == nullptr) return false;
    if(root->val == k && root != skip) return true;
    else if(root->val > k) return find(root->left, k, skip);
    else return find(root->right, k, skip);
  }

  bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
      TreeNode* node = s.top(); s.pop();
      if(node == nullptr) continue;
      if(find(root, k - node->val, node)) return true;

      s.push(node->left);
      s.push(node->right);
    }
    return false;
  }
};

int main(){
  return 0;
}