#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <array>

using namespace std;

class Solution {
public:
    int getCode(char c){
      if(c == 'a'){
        return 0;
      }else if(c == 'e'){
        return 1;
      }else if(c == 'i'){
        return 2;
      }else if(c == 'o'){
        return 3;
      }else if(c == 'u'){
        return 4;
      }else{
        return -1;
      }
    }
  
    int findTheLongestSubstring(string s) {
      array<int, 32> s_type, e_type;
      s_type.fill(s.size());
      e_type.fill(-1);
      
      // precompute
      bitset<5> status(0);
      for(int i = 0; i < s.size(); ++i){
        // start type
        if(i == 0 || getCode(s[i-1]) != -1){
          s_type[status.to_ullong()] = min(s_type[status.to_ullong()], i);
        }
        
        // change status
        int code = getCode(s[i]);
        if(code != -1){
          status.flip(code);
        }

        // end type
        if(i == s.size()-1 || getCode(s[i+1]) != -1){
          e_type[status.to_ullong()] = max(e_type[status.to_ullong()], i);
        }
      }

      // find longest
      int longest = -1;
      for(int i = 0; i < 32; ++i){
        longest = max(longest, (e_type[i] - s_type[i] + 1));
      }

      return longest;
    }
};

int main(){
  Solution s;
  cerr << s.findTheLongestSubstring("qnplnlarrtztkotazhufrsfczrzibvccaoayyihidztfljcffiqfviuwjowkppdajmknzgidixqgtnahamebxfowqvnrhuzwqohquamvszkvunbxjegbjccjjxfnsiearbsgsofywtqbmgldgsvnsgpdvmjqpaktmjafgkzszekngivdmrlvrpyrhcxbceffrgiyktqilkkdjhtywpesrydkbncmzeekdtszmcsrhsciljsrdoidzbjatvacndzbghzsnfdofvhfxdnmzrjriwpkdgukbaazjxtkomkmccktodig");

  return 0;
}