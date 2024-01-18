class WordDictionary {
public:
  struct cmp{
    bool operator()(const string &a, const string &b) const {
      if(a.size() != b.size()) return a.size() < b.size();
      return a < b;
    }
  };

  set<string, cmp> s;

  WordDictionary() {

  }

  void addWord(string word) {
    s.insert(word);
  }

  bool search(string word) {
    string tmpa = word, tmpb = word;
    for(int i = 0; i < word.size(); ++i){
      if(word[i] == '.'){ 
        tmpa[i] = 0;
        tmpb[i] = 127;
      }
    }
    auto start = s.lower_bound(tmpa);
    auto end = s.upper_bound(tmpb);
    if(start == s.end()) return false;
    for(auto it = start; it != end; it++){
      string found = *it;
      bool accept = true;
      for(int i = 0; i < word.size(); ++i){
        if(word[i] != '.' && word[i] != found[i]){
          accept = false;
          break;
        }
      }
      if(accept) return true;
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
