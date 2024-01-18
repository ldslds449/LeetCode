/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  void s_helper(TreeNode* now, string &s) {
    s += "(";
    if(now != nullptr){
      s += to_string(now->val);
      s_helper(now->left, s);
      s_helper(now->right, s);
    }
    s += ")";
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s = "";
    s_helper(root, s);
    return s;
  }

  TreeNode* d_helper(const string &s, int &idx){
    idx++;  // (
    if(s[idx] == ')'){
      idx++;  // )
      return nullptr;
    }
    int end = s.find_first_of("(", idx);
    int val = stoi(s.substr(idx, end-idx));
    TreeNode* node = new TreeNode(val);
    idx = end;
    node->left = d_helper(s, idx);
    node->right = d_helper(s, idx);
    idx++;  // )
    return node;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int idx = 0;
    return d_helper(data, idx);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
