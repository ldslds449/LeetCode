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
  void task(TreeNode* parent, TreeNode* child, int val, int depth){
    if(child == nullptr) return;
    if(depth == 1){
      child->left = new TreeNode(val, child->left, nullptr);
      child->right = new TreeNode(val, nullptr, child->right);
    }else if(depth > 1){
      task(child, child->left, val, depth-1);
      task(child, child->right, val, depth-1);
    }
    return;
  }

  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    TreeNode* realRoot = new TreeNode(0, root, nullptr);
    task(nullptr, realRoot, val, depth);
    return realRoot->left;
  }
};

int main(){
  return 0;
}