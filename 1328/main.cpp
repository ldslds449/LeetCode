#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string breakPalindrome(string palindrome) {
    if(palindrome.size() == 1) return "";

    for(int i = 0; i < palindrome.size(); ++i){
      for(int k = 'a'; k < palindrome[i]; ++k){
        if(k != palindrome[palindrome.size()-1-i] && i != palindrome.size()-1-i){
          palindrome[i] = k;
          return palindrome;
        }
      }
    }

    for(int i = palindrome.size()-1; i >= 0; --i){
      for(int k = palindrome[i]+1; k < 'z'; ++k){
        if(k != palindrome[palindrome.size()-1-i] && i != palindrome.size()-1-i){
          palindrome[i] = k;
          return palindrome;
        }
      }
    }

    return "";
  }
};

int main(){
  return 0;
}