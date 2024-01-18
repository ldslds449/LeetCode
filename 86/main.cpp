/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *prev = new ListNode(), *next = new ListNode();
    ListNode *prev_root = prev, *next_root = next;
    while(head != nullptr){
      ListNode **t = (head->val < x ? &prev : &next);
      (*t)->next = head;
      (*t) = head;
      head = head->next;
    }
    prev->next = next_root->next;
    next->next = nullptr;
    return prev_root->next;
  }
};
