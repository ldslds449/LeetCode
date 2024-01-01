class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    stack<int> st;
    vector<int> table(seq.size());
    int max_val = 0;
    for(int i = 0; i < seq.size(); ++i){
      if(seq[i] == '(') st.push(i);
      else{
        int remain = st.size()-1;
        table[st.top()] = remain;
        table[i] = remain;
        st.pop();
        max_val = max(max_val, remain);
      }
    }
    int half = (max_val+1)/2;
    for(int i = 0; i < table.size(); ++i){
      table[i] = (table[i] < half ? 0 : 1);
    }
    return table;
  }
};
