/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start

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
    int total = 0;

    void dfs(TreeNode* root, int prefix){
        if(!root) return;
        prefix = prefix*10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            total += prefix;
        }else{
            dfs(root->left, prefix);
            dfs(root->right, prefix);
        }
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return total;
    }
};
// @lc code=end

