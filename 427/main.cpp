/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
  Node* helper(vector<vector<int>> &grid, int startX, int endX, int startY, int endY) {
    int val = grid[startX][startY];
    Node *node = new Node(val, true);
    bool same = true;
    for(int i = startX; i < endX; ++i){
      for(int j = startY; j < endY; ++j){
        if(grid[i][j] != val){ same = false; break; }
      }
    }
    if(same) return node;
    else{
      int midX = (endX - startX) / 2 + startX;
      int midY = (endY - startY) / 2 + startY;
      node->isLeaf = false;
      node->topLeft = helper(grid, startX, midX, startY, midY);
      node->bottomLeft = helper(grid, midX, endX, startY, midY);
      node->topRight = helper(grid, startX, midX, midY, endY);
      node->bottomRight = helper(grid, midX, endX, midY, endY);
    }
    return node;
  }

  Node* construct(vector<vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid.front().size();
    return helper(grid, 0, M, 0, N);
  }
};
