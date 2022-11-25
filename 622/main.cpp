#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
  int start, end;
  vector<int> list;
public:
  MyCircularQueue(int k):list(k+1) {
    start = end = 0;
  }
  
  bool enQueue(int value) {
    int next = (end + 1) % list.size();
    if(next == start){ // full
      return false;
    }else{
      list[end] = value;
      // move pointer
      end = next;
      return true;
    }
  }
  
  bool deQueue() {
    if(end == start){ // empty
      return false;
    }else{
      // move pointer
      start = (start + 1) % list.size();
      return true;
    }
  }
  
  int Front() {
    return (end == start ? -1 : list[start]);
  }
  
  int Rear() {
    int prev = (end + list.size() - 1) % list.size();
    return (end == start ? -1 : list[prev]);
  }
  
  bool isEmpty() {
    return (end == start);
  }
  
  bool isFull() {
    int next = (end + 1) % list.size();
    return (next == start);
  }
};

int main(){
  return 0;
}