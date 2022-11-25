#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  Node *next, *prev;
  int val;

  Node(int _val, Node* _next = nullptr, Node* _prev = nullptr){
    this->val = _val;
    this->next = _next;
    this->prev = _prev;
  }
};

class FrontMiddleBackQueue {
private:
  Node *s_ptr, *m_ptr, *b_ptr;
  int size = 0;
public:
  FrontMiddleBackQueue() {
    s_ptr = m_ptr = b_ptr = nullptr;
  }

  void print(){
    cerr << " -- ";
    auto tmp = s_ptr;
    for(int i = 0; i < size; ++i){
      cerr << tmp->val << " ";
      tmp = tmp->next;
    } 
    cerr << "[";
    cerr << (s_ptr == nullptr ? -1 : s_ptr->val) << " ";
    cerr << (m_ptr == nullptr ? -1 : m_ptr->val) << " ";
    cerr << (b_ptr == nullptr ? -1 : b_ptr->val) << "]\n";
  }
  
  void pushFront(int val) {
    s_ptr = new Node(val, s_ptr, nullptr);
    if(size == 0){
      m_ptr = b_ptr = s_ptr;
    }else{
      s_ptr->next->prev = s_ptr;
      if((size & 1) == 1){ // odd
        // middle move front
        m_ptr = m_ptr->prev;
      }
    }
    size++;
  }
  
  void pushMiddle(int val) {
    bool start_equal = (s_ptr == m_ptr);
    if((size & 1) == 0){ // even
      // add back
      Node* next = (m_ptr == nullptr ? nullptr : m_ptr->next);
      m_ptr = new Node(val, next, m_ptr);
    }else{ // odd
      // add front
      m_ptr = new Node(val, m_ptr, m_ptr->prev);
      if(start_equal){
        s_ptr = m_ptr;
      }
    }
    if(m_ptr->next != nullptr){
      m_ptr->next->prev = m_ptr;
    }
    if(m_ptr->prev != nullptr){
      m_ptr->prev->next = m_ptr;
    }
    if(size == 0){
      s_ptr = b_ptr = m_ptr;
    }
    size++;
  }
  
  void pushBack(int val) {
    b_ptr = new Node(val, nullptr, b_ptr);
    if(size == 0){
      s_ptr = m_ptr = b_ptr;
    }else{
      b_ptr->prev->next = b_ptr;
      if((size & 1) == 0){ // even
        // middle move back
        m_ptr = m_ptr->next;
      }
    }
    size++;
  }
  
  int popFront() {
    if(size == 0){
      return -1;
    }else{
      bool mid_equal = (s_ptr == m_ptr);
      int val = s_ptr->val;
      Node* next = s_ptr->next;
      delete s_ptr;

      if(next != nullptr){
        next->prev = nullptr;
      }
      s_ptr = next;
      if(mid_equal){
        m_ptr = s_ptr;
      }else{
        if((size & 1) == 0){ // even
          // middle move back
          m_ptr = m_ptr->next;
        }
      }
      
      size--;
      if(size == 0){ // reset
        s_ptr = m_ptr = b_ptr = nullptr;
      }

      return val;
    }
  }
  
  int popMiddle() {
    if(size == 0){
      return -1;
    }else{
      int val = m_ptr->val;
      // connect
      if(m_ptr->next != nullptr){
        m_ptr->next->prev = m_ptr->prev;
      }
      if(m_ptr->prev != nullptr){
        m_ptr->prev->next = m_ptr->next;
      }
      Node* del = m_ptr;
      if((size & 1) == 0){ // even
        // middle move back
        m_ptr = m_ptr->next;
        if(s_ptr == del){
          s_ptr = m_ptr;
        }
      }else{ // odd
        // middle move front
        m_ptr = m_ptr->prev;
      }
      delete del;
      size--;
      if(size == 0){ // reset
        s_ptr = m_ptr = b_ptr = nullptr;
      }
      return val;
    }
  }
  
  int popBack() {
    if(size == 0){
      return -1;
    }else{
      bool mid_equal = (b_ptr == m_ptr);
      int val = b_ptr->val;
      Node* prev = b_ptr->prev;
      delete b_ptr;
      
      if(prev != nullptr){
        prev->next = nullptr;
      }
      b_ptr = prev;
      if(mid_equal){
        m_ptr = b_ptr;
      }else{
        if((size & 1) == 1){ // odd
          // middle move front
          m_ptr = m_ptr->prev;
        }
      }
      
      size--;
      if(size == 0){ // reset
        s_ptr = m_ptr = b_ptr = nullptr;
      }

      return val;
    }
  }
};

int main(){

  FrontMiddleBackQueue q;
  q.pushMiddle(874835); q.print();
  cerr << q.popBack(); q.print();
  cerr << q.popMiddle(); q.print();
  cerr << q.popMiddle(); q.print();
  q.pushBack(319750); q.print();
  q.pushFront(782168); q.print();
  cerr << q.popFront(); q.print();
  q.pushMiddle(16473); q.print();
  q.pushMiddle(495349); q.print();
  cerr << q.popMiddle(); q.print();
  cerr << q.popMiddle(); q.print();
  q.pushMiddle(596131); q.print();
  cerr << q.popMiddle(); q.print();
  q.pushMiddle(583563); q.print();

  return 0;
}