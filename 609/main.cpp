#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    struct Info{
      string path;
      string content;
    };
  
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      vector<Info> files;

      for(string &p : paths){
        // get files & contents
        string folder = "";
        stringstream ss, ss_content;
        bool isContent = false;
        for(int i = 0; i <= p.size(); ++i){
          if(i == p.size() || p[i] == ' '){ 
            if(folder == ""){ // folder
              folder = ss.str();
              ss.str("");
            }else{ // file
              Info info;
              info.path = folder + '/' + ss.str();
              info.content = ss_content.str();
              files.push_back(info);
              ss.str("");
              ss_content.str("");
            }
          }else if(p[i] == '('){
            isContent = true;
          }else if(p[i] == ')'){
            isContent = false;
          }else{
            if(isContent){
              ss_content << p[i];
            }else{
              ss << p[i];
            }
          }
        }
      }
      
      // sort
      sort(files.begin(), files.end(), [](Info &a, Info &b)-> bool{
        return a.content < b.content;
      });

      // find duplicate
      vector<vector<string>> result;
      int pre_diff = 0;
      for(int i = 1; i <= files.size(); ++i){
        if(i == files.size() || files[i-1].content != files[i].content){
          if(i - pre_diff > 1){ // duplicate
            vector<string> r;
            for(int k = pre_diff; k < i; ++k){
              r.push_back(files[k].path);
            }
            result.push_back(r);
          }
          pre_diff = i;
        }
      }
      return result;
    }
};

int main(){
  Solution s;

  cerr << s.trap({0,1,0,2,1,0,1,3,2,1,2,1});

  return 0;
}