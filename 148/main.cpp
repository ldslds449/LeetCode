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
  ListNode* helper(ListNode* head, int total){
    if(total <= 1) return head;
    // divide
    int p_cnt = total / 2, n_cnt = total - p_cnt;
    int cnt = 0;
    ListNode *prev = nullptr, *now = head;
    while(cnt < p_cnt){
      cnt++;
      prev = now;
      now = now->next;
    }
    prev->next = nullptr;
    ListNode *a, *b;
    a = helper(head, p_cnt);
    b = helper(now, n_cnt);
    // merge
    ListNode *c = nullptr, *c_head = nullptr;
    while(a != nullptr && b != nullptr){
      ListNode *select;
      if(a->val < b->val){
        select = a;
        a = a->next;
      }else{
        select = b;
        b = b->next;
      }
      if(c == nullptr){ 
        c = select; 
        c_head = c;
      }else{
        c->next = select;
        c = c->next;
      }
    }
    if(a != nullptr) c->next = a;
    if(b != nullptr) c->next = b;
    return c_head;
  }

  ListNode* sortList(ListNode* head) {
    ListNode *now = head;
    int cnt = 0;
    while(now != nullptr){
      cnt++;
      now = now->next;
    }
    return helper(head, cnt);
  }
};
