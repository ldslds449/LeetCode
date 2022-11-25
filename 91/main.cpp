#include <iostream>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
  array<int,100> table;

  int recursive(int now, const string &s){
    // out of bound
    if(now >= s.size()){
      return now == s.size();
    }
    // cache
    if(table[now] != -1){
      return table[now];
    }
    // main
    if(s[now] == '0'){
      return 0;
    }
    int a = recursive(now+1, s), b = 0;
    if(s[now] == '1'){
      b = recursive(now+2, s);
    }else if(s[now] == '2'){
      if(now+1 < s.size() && s[now+1] >= '0' && s[now+1] <= '6'){
        b = recursive(now+2, s);
      }
    }
    table[now] = a+b;
    return a+b;
  }

  int numDecodings(string s) {
    table.fill(-1);
    return recursive(0, s);
  }
};

int main(){
  return 0;
}