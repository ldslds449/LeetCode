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

struct Data{
  TreeNode* node;
  int preSum;
  vector<int> path;
};

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    vector<vector<int>> result;
    
    stack<Data> s;
    if(root != nullptr){
      Data root_data; 
      root_data.node = root; 
      root_data.preSum = root->val; 
      root_data.path = vector<int>{root->val}; 
      s.push(root_data);
    }

    while(!s.empty()){
      auto node = s.top(); s.pop();
      if(node.node->left == nullptr && node.node->right == nullptr) { // leaf
        if(node.preSum == targetSum) { // found
          result.push_back(node.path);
        }
        continue;
      }

      if(node.node->left != nullptr){
        Data tmp = node;
        tmp.node = node.node->left;
        tmp.preSum += node.node->left->val;
        tmp.path.push_back(node.node->left->val);
        s.push(tmp);
      }

      if(node.node->right != nullptr){
        Data tmp = node;
        tmp.node = node.node->right;
        tmp.preSum += node.node->right->val;
        tmp.path.push_back(node.node->right->val);
        s.push(tmp);
      }
    }
    
    return result;
  }
};

int main(){
  return 0;
}