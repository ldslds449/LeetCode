/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start

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

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start_in, int end_in, int start_post, int end_post){
        if(start_in >= end_in) return nullptr;

        int mid = postorder[end_post-1], mid_idx = 0;
        while(inorder[start_in + mid_idx] != mid) mid_idx++;

        TreeNode* node = new TreeNode(mid,
            helper(inorder, postorder, start_in, start_in+mid_idx, start_post, start_post+mid_idx),
            helper(inorder, postorder, start_in+mid_idx+1, end_in, start_post+mid_idx, end_post-1));
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
// @lc code=end

