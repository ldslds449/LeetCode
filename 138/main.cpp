/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mapping;
    Node *dummy = new Node(0), *tmp = head;
    Node *d_tmp = dummy;
    while(tmp != nullptr){
      d_tmp->next = new Node(tmp->val);
      mapping[tmp] = d_tmp->next;
      d_tmp = d_tmp->next;
      tmp = tmp->next;
    }
    dummy = dummy->next;
    d_tmp = dummy;
    while(head != nullptr){
      dummy->random = mapping[head->random];
      dummy = dummy->next;
      head = head->next;
    }
    return d_tmp;
  }
};
