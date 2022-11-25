#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
  int start, end, el_size;
  vector<int> list;
public:
  MyCircularDeque(int k): list(k) {
    start = end = el_size = 0;
  }
  
  bool insertFront(int value) {
    if(el_size == list.size()){ // full
      return false;
    }else{
      start = (start-1 + list.size()) % list.size();
      list[start] = value;
      el_size++;
      return true;
    }
  }
  
  bool insertLast(int value) {
    if(el_size == list.size()){ // full
      return false;
    }else{
      list[end] = value;
      end = (end + 1) % list.size();
      el_size++;
      return true;
    }
  }
  
  bool deleteFront() {
    if(el_size == 0){ // empty
      return false;
    }else{
      start = (start + 1) % list.size();
      el_size--;
      return true;
    }
  }
  
  bool deleteLast() {
    if(el_size == 0){ // empty
      return false;
    }else{
      end = (end-1 + list.size()) % list.size();
      el_size--;
      return true;
    }
  }
  
  int getFront() {
    return (el_size == 0 ? -1 : list[start]);
  }
  
  int getRear() {
    int prev = (end-1 + list.size()) % list.size();
    return (el_size == 0 ? -1 : list[prev]);
  }
  
  bool isEmpty() {
    return el_size == 0;
  }
  
  bool isFull() {
    return el_size == list.size();
  }
};

int main(){
  return 0;
}