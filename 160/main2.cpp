/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *orig_A = headA;
    while(headA != nullptr){
      headA->val = -headA->val;
      headA = headA->next;
    }
    ListNode *ans = nullptr;
    while(headB != nullptr){
      if(headB->val < 0){
        ans = headB;
        break;
      }
      headB = headB->next;
    }
    headA = orig_A;
    while(headA != nullptr){
      headA->val = -headA->val;
      headA = headA->next;
    }
    return ans;
  }
};
