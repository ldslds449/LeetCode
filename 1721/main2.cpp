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
    ListNode *front, *rear;
    ListNode *begin = head, *end = head;

    for(int i = 0; i < k-1; ++i){
      end = end->next;
    }
    front = end;

    while(end ->next != nullptr){
      end = end->next;
      begin = begin->next;
    }
    rear = begin;

    swap(front->val, rear->val);

    return head;
  }
};