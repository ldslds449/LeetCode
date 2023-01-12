/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start

#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left = p->val, right = q->val;
        if(left > right) swap(left, right);

        while(!(left <= root->val && root->val <= right)){
            if(root->val < left){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return root;
    }
};
// @lc code=end

