/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        // find depth
        TreeNode* ptr = root;
        int depth = -1;
        while(ptr != nullptr){
            depth++;
            ptr = ptr->left;
        }

        if(depth == -1) return 0;
        if(depth == 0) return 1;

        // binary search
        int left = 0, right = (1<<depth);
        int count;
        while(left < right){
            int mid = (right-left)/2 + left;
            // find node
            ptr = root;
            for(int i = 0, k = (1<<(depth-1)); i < depth; ++i, k >>= 1){
                if(mid&k){
                    ptr = ptr->right;
                }else{
                    ptr = ptr->left;
                }
            }
            if(ptr == nullptr){
                count = (1<<(depth))-1 + mid;
                right = mid;
            }else{
                count = (1<<(depth))-1 + mid + 1;
                left = mid+1;
            }
        }
        
        return count;
    }
};
// @lc code=end

