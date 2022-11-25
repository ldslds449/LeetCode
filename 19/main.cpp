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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *remove_prev, *tail;
    tail = head; remove_prev = nullptr;

    // find
    for(int i = 0; i < n-1; ++i){
      tail = tail->next;
    }
    while(tail->next != nullptr){
      tail = tail->next;
      if(remove_prev == nullptr){
        remove_prev = head;
      }else{
        remove_prev = remove_prev->next;
      }
    }

    // remove
    if(remove_prev == nullptr){
      head = head->next;
    }else{
      if(remove_prev->next != nullptr){
        remove_prev->next = remove_prev->next->next;
      }
    }

    return head;
  }
};

int main(){
  return 0;
}