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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right) return head;
    ListNode *root = new ListNode(0, head);
    ListNode *prev = root, *now = head;
    int count = 1;
    while(count < left){
      prev = now;
      now = now->next;
      count++;
    }
    ListNode *tmp, *left_prev = prev;
    while(count <= right){
      tmp = now->next;
      now->next = prev;
      prev = now;
      now = tmp;
      count++;
    }
    left_prev->next->next = now;
    left_prev->next = prev;
    return root->next;
  }
};
