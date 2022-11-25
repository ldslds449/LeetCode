#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Data{
  int timestamp;
  string value;
  Data(int _timestamp, string _value): timestamp(_timestamp), value(_value) {}
};

class TimeMap {
public:
  unordered_map<string, vector<Data>> Map;

  TimeMap() {
    
  }
  
  void set(string key, string value, int timestamp) {
    auto it = Map.find(key);
    if(it == Map.end()){
      Map[key] = {Data(timestamp, value)};
    }else{
      it->second.push_back(Data(timestamp, value));
    }
  }
  
  string get(string key, int timestamp) {
    auto it = Map.find(key);
    if(it == Map.end()){
      return "";
    }

    // binary-search
    int start = 0, end = it->second.size();
    auto &arr = it->second;
    while(start < end){
      int mid = (end-start)/2 + start;
      if(arr[mid].timestamp == timestamp){
        return arr[mid].value;
      }else if(arr[mid].timestamp > timestamp){
        end = mid;
      }else{
        start = mid+1;
      }
    }
    
    if(start-1 >= 0){
      return arr[start-1].value;
    }else{
      return "";
    }
  }
};

int main(){
  return 0;
}