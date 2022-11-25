#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class MyCalendarThree {
public:
  vector<pair<int,int>> order;
  int max_overlap = 0;

  MyCalendarThree() {}
  
  int book(int start, int end) {
    int overlap = 1;
    vector<pair<int,int>> arr; // time, type
    
    for(int i = 0; i < order.size(); ++i){
      if(order[i].first < start && 
         order[i].second > start && order[i].second <= end){ // type 1
        overlap++;
        arr.push_back({order[i].second, -1});
      }else if(order[i].first >= start && order[i].first < end && 
         order[i].second > end){ // type 2
        arr.push_back({order[i].first, 1});
      }else if(order[i].first < start && order[i].second > end){ // type 3
        overlap++;
      }else if(order[i].first >= start && order[i].first < end &&
              order[i].second > start && order[i].second <= end){ // type 4
        arr.push_back({order[i].first, 1});
        arr.push_back({order[i].second, -1});
      }
    }
    
    // sort
    sort(arr.begin(), arr.end(), [](pair<int,int> &a, pair<int,int> &b) -> bool{
      return a.first < b.first;
    });
    
    max_overlap = max(max_overlap, overlap);
    int idx = 0;
    while(idx < (int)arr.size()){
      do{
        overlap += arr[idx].second;
        idx++;
      }while(idx < arr.size() && arr[idx].first == arr[idx-1].first);
      
      max_overlap = max(max_overlap, overlap);
    }
    
    order.push_back({start, end});
      
    return max_overlap;
  }
};


int main(){
  MyCalendarThree s;
  cerr << s.book(10,20) << "\n";
  cerr << s.book(50,60) << "\n";
  cerr << s.book(10,40) << "\n";
  cerr << s.book(5,15) << "\n";
  return 0;
}