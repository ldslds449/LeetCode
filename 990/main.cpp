#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <bitset>

using namespace std;

class Solution {
public:

  array<int8_t,26> parent;
  array<array<bool,26>,26> table; // 0: no relation, 1: different

  int findRoot(int op){
    vector<int> vec;
    while(parent[op] != op){
      vec.push_back(op);
      op = parent[op];
    }
    for(int &tmp : vec){ // point to root
      parent[tmp] = op;
    }
    return op;
  }

  bool equationsPossible(vector<string>& equations) {
    
    for(int i = 0; i < 26; ++i){
      for(int k = 0; k < 26; ++k){
        table[i][k] = false; // self-connect
      }
    }
    parent.fill(-1);
    
    for(auto &s : equations){
      char op1 = s[0] - 'a';
      char op2 = s[3] - 'a';
      bool opt = s[1] == '=';

      if(opt){
        if(parent[op1] == -1 && parent[op2] == -1){
          parent[op1] = parent[op2] = op1;
        }else if(parent[op1] != -1 && parent[op2] == -1){
          parent[op2] = parent[op1];
        }else if(parent[op1] == -1 && parent[op2] != -1){
          parent[op1] = parent[op2];
        }else{
          int op1_root = findRoot(op1);
          int op2_root = findRoot(op2);
          cerr << s << " " << op1_root << " " << op2_root << "\n";
          if(op1_root != op2_root){
            if(table[op1_root][op2_root] == true){
              return false;
            }else{
              // merge
              parent[op2_root] = op1_root; 
              for(int i = 0; i < 26; ++i){
                if(table[op2_root][i]){
                  table[op1_root][i] = true;
                  table[i][op1_root] = true;
                }
              }
            }
          }
        }
      }else{
        if(parent[op1] == -1){
          parent[op1] = op1;
        }
        if(parent[op2] == -1){
          parent[op2] = op2;
        }
        int op1_root = findRoot(op1);
        int op2_root = findRoot(op2);
        cerr << op1_root << " " << op2_root << "\n";
        if(op1_root == op2_root){
          return false;
        }
        table[op1_root][op2_root] = true;
        table[op2_root][op1_root] = true;
      }
    }
    return true;
  }
};

int main(){

  vector<string> vec{"a==b","e==c","b==c","a!=e"};

  Solution s;
  s.equationsPossible(vec);

  return 0;
}