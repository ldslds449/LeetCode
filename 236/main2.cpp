/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start

#include <vector>

using namespace std;

// Definition for singly-linked list.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* ans = nullptr;

    bool helper(TreeNode* root, TreeNode* &p, TreeNode* &q){
        if(!root) return false;
        bool same = root == p || root == q;
        bool found_left = helper(root->left, p, q);
        if(ans) return true;
        bool found_right = helper(root->right, p, q);
        if(ans) return true;
        if((found_left && found_right) || ((found_left || found_right) && same)){
          ans = root;
          return true;
        }
        return same || (found_left || found_right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};
// @lc code=end

