/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  void helper(Node* root, vector<Node*> &prev, int level){
    if(root == nullptr) return;
    if(prev.size() > level){
      prev[level]->next = root;
      prev[level] = root;
    }else{
      prev.push_back(root);
    }
    helper(root->left, prev, level+1);
    helper(root->right, prev, level+1);
  }

  Node* connect(Node* root) {
    vector<Node*> prev;
    helper(root, prev, 0);
    return root;
  }
};
