class LRUCache {
public:
  class Node {
  public:
    int val, key;
    Node *next, *prev;
  };
  
  const int cap;
  unordered_map<int, Node*> table;
  Node *head, *tail;

  LRUCache(int capacity) : cap(capacity), head(nullptr), tail(nullptr) {}

  void moveToHead(Node* node) {
    // move to the head
    if(head != node){
      node->prev->next = node->next;
      if(node->next != nullptr){
        node->next->prev = node->prev;
      }
      if(tail == node){
        tail = node->prev;
      }
      node->prev = nullptr;
      node->next = head;
      head->prev = node;
      head = node;
    }
  }

  int get(int key) {
    if(table.count(key) == 0){
      return -1;
    }
    moveToHead(table[key]);
    return table[key]->val;
  }

  void put(int key, int value) {
    if(table.count(key) == 0){
      Node *node = new Node();
      node->key = key;
      node->val = value;
      node->next = head;
      node->prev = nullptr;
      table[key] = node;
      
      // push into head
      if(head == nullptr){
        head = tail = node;
      }else{
        head->prev = node;
        head = node;
      }
      
      // if exceed the capacity, pop from tail
      if(table.size() > cap){
        Node *del = tail;
        tail = tail->prev;
        if(tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        table.erase(del->key);
        delete del;
      }
    }else{
      Node *node = table[key];
      node->val = value;
      moveToHead(node);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

