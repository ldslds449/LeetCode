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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *begin, *end, *now;
    begin = head; end = head;
    // find
    for(int i = 0; i < k-1; ++i){
      begin = begin->next;
    }
    now = begin;
    while(now->next != nullptr){
      end = end->next;
      now = now->next;
    }
    //swap
    swap(begin->val, end->val);

    return head;
  }
};

int main(){
  return 0;
}