#include <string>

using namespace std;

class Solution {
public:
    inline bool isVowel(char c){
        return c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u';
    }

    int maxVowels(string s, int k) {
        int len = 0;
        int cnt = 0, max_cnt = -1;;
        for(int i = 0; i < s.size(); ++i){
            cnt += isVowel(s[i]);
            if(len == k){
                cnt -= isVowel(s[i-k]);
            }else{
                len++;
            }
            max_cnt = max(max_cnt, cnt);
        }

        return max_cnt;
    }
};