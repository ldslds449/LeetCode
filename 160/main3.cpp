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
    int lenA = 0, lenB = 0;
    ListNode *tmpA = headA;
    while(tmpA != nullptr){
      lenA++;
      tmpA = tmpA->next;
    }
    ListNode *tmpB = headB;
    while(tmpB != nullptr){
      lenB++;
      tmpB = tmpB->next;
    }

    while(lenA > lenB){
      headA = headA->next;
      lenA--;
    }
    while(lenA < lenB){
      headB = headB->next;
      lenB--;
    }

    while(headA != nullptr){
      if(headA == headB) return headA;
      headA = headA->next;
      headB = headB->next;
    }

    return nullptr;
  }
};
