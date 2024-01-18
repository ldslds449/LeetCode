class WordDictionary {
public:
  class Node{
  public:
    vector<Node*> child;
    char val;
    bool isLeaf;
    Node(char c) : child(26, nullptr) {
      val = c;
      isLeaf = false;
    }
  };

  Node *root;

  WordDictionary() {
    root = new Node(' ');
  }

  void addWord(string word) {
    Node *cur = root;
    for(int i = 0; i < word.size(); ++i){
      Node* &entry = cur->child[word[i]-'a'];
      if(entry == nullptr){
        entry = new Node(word[i]);
      }
      cur = entry;
    }
    cur->isLeaf = true;
  }

  bool search(string word) {
    stack<pair<Node*,int>> st;
    st.push({root, 0});
    while(!st.empty()){
      auto p = st.top(); st.pop();
      Node* cur = p.first;
      int idx = p.second;
      if(idx == word.size()){
        if(cur->isLeaf) return true;
        else continue;
      }

      char c = word[idx];
      if(c == '.'){
        for(Node *n : cur->child){
          if(n != nullptr){
            st.push({n, idx+1});
          }
        }
      }else{
        Node* next = cur->child[c-'a'];
        if(next == nullptr) continue;
        st.push({next, idx+1});
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
