#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *root = new ListNode(0, head);
    ListNode *now = root;

    while(now->next != nullptr && now->next->next != nullptr){
      // swap
      ListNode *tmp = now->next;
      now->next = now->next->next;
      tmp->next = now->next->next;
      now->next->next = tmp;
      // move
      now = tmp;
    }

    return root->next;
  }
};

int main(){
  return 0;
}