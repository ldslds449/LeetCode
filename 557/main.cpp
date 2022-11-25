#include <string>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      stack<char> st;
      ostringstream ss("");
      
      // read
      for(unsigned i = 0; i <= s.size(); ++i){
        char &c = s[i];
        if(i == s.size() || c == ' '){
          // add word
          while(!st.empty()){
            ss << st.top();
            st.pop();
          }
          // add whitespace
          if(c == ' '){
            ss << ' ';
          }
        }else{
          st.push(c);
        }
      }

      return ss.str();
    }
};

int main(){

  return 0;
}