class Solution {
public:
  string simplifyPath(string path) {
    stack<string> st;
    int pos = 0;
    while(pos < path.size()){
      auto idx = path.find_first_of("/", pos);
      if(idx == string::npos) idx = path.size();
      string str(path.begin()+pos, path.begin()+idx);
      if(str == ".."){
        if(!st.empty()) st.pop();
      }else if(str != "." && str.size() > 0){
        st.push(str);
      }
      pos = idx;
      while(path[pos] == '/') pos++;
    }

    string ans = "";
    while(!st.empty()){
      ans.insert(0, "/" + st.top());
      st.pop();
    }
    return ans == "" ? "/" : ans;
  }
};
