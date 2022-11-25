#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
  Node *left, *right;
  int max_val;
  int start, end;
  Node(int _start, int _end, int _max_val){
    this->start = _start;
    this->end = _end;
    this->max_val = _max_val;
    this->left = nullptr;
    this->right = nullptr;
  }
};


class MyCalendarThree {
public:

  Node* root;

  MyCalendarThree() { root = new Node(0, 1e9+1, 0); }

  int modify(Node* node, int start, int end){
    if(start == end) return 0;
    if(node->start == start && node->end == end && node->left == nullptr && node->right == nullptr){
      node->max_val++;
      return node->max_val;
    }
    int mid = (node->end-node->start)/2 + node->start;
    if(node->left == nullptr){
      if(mid-node->start > 0) node->left = new Node(node->start, mid, node->max_val);
    }
    if(node->right == nullptr){
      if(node->end-mid > 0) node->right = new Node(mid, node->end, node->max_val);
    }
    if(end < mid){
      node->max_val = max(node->max_val, modify(node->left, start, end));
    }else if(start >= mid){
      node->max_val = max(node->max_val, modify(node->right, start, end));
    }else{
      int m1 = modify(node->left, start, mid);
      int m2 = modify(node->right, mid, end);
      node->max_val = max(node->max_val, max(m1, m2));
    }
    return node->max_val;
  }
  
  int book(int start, int end) {
    return modify(root, start, end);
  }

  void walk(Node* node){
    if(node == nullptr) return;
    cout << "(" << node->start << " " << node->end << ") " << node->max_val << "\n";
    walk(node->left);
    walk(node->right);
  }
};

int main(){
  MyCalendarThree p;
  // p.walk(p.root); cout << "=========\n";
  cout << p.book(47, 50);
  cout << p.book(1, 10);
  cout << p.book(27, 36);
  cout << p.book(40, 47);
  cout << p.book(20, 27);
  cout << p.book(15, 23);
  // cout << p.book(10, 18);
  // cout << p.book(27, 36);
  // cout << p.book(17, 25);
  // cout << p.book(8, 17);
  // cout << p.book(24, 33);
  // cout << p.book(23, 28);
  p.walk(p.root);
}
