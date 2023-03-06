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
    TreeNode *ans, *p, *q;
    bool found_p = false, found_q = false;

    bool helper(TreeNode* root, TreeNode* anc){
        if(root == nullptr) return false;
        if(!found_p && !found_q){
            if(root == p) found_p = true;
            else if(root == q) found_q = true;

            return helper(root->left, root) || helper(root->right, root);
        }else{
            if((!found_p && root == p) || (!found_q && root == q)){
                ans = anc;
                return true;
            }
            return helper(root->left, anc) || helper(root->right, anc);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        helper(root, nullptr);
        return ans;
    }
};
// @lc code=end

