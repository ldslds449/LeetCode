/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// @lc code=start

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = nullptr, *even = nullptr;
        ListNode *odd_tail = nullptr, *even_tail = nullptr;

        int count = 1;
        while(head != nullptr){
            ListNode **target = (count & 1) ? &odd : &even;
            ListNode **target_tail = (count & 1) ? &odd_tail : &even_tail;
            if(*target == nullptr){
                *target = *target_tail = head;
            }else{
                (*target_tail)->next = head;
                (*target_tail) = head;
            }
            head = head->next;
            count++;
        }

        if(even_tail != nullptr) even_tail->next = nullptr;
        if(odd_tail != nullptr) odd_tail->next = even;
        return odd;
    }
};
// @lc code=end

