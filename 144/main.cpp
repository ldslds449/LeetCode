/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> r;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top(); s.pop();
            r.push_back(node->val);
            if(node->right != nullptr) s.push(node->right);
            if(node->left != nullptr) s.push(node->left);
        }
        return r;
    }
};
// @lc code=end

