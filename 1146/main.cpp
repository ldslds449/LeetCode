#include <list>
#include <vector>
#include <utility>

using namespace std;

class SnapshotArray {
public:
  vector<list<pair<int,int>>> record;
  int id = 0;
  
  SnapshotArray(int length) {
    record.resize(length);
    for(int i = 0; i < length; ++i){
      record[i].push_back({0, -1});
    }
  }
  
  void set(int index, int val) {
    if(record[index].back().second != id){
      record[index].push_back({val, id});
    }else{
      record[index].back().first = val;
    }
    
  }
  
  int snap() {
    return id++;
  }
  
  int get(int index, int snap_id) {
    auto it = record[index].begin();
    int now_val;
    while(snap_id >= it->second && it != record[index].end()){
      now_val = it->first;
      it++;
    }
    return now_val;
  }
};