/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <string>
#include <iostream>

using namespace std;

// @lc code=start

#define CODE(c) (c >= 'a' && c <= 'z' ? c-'a' : c-'A'+26)

class Solution {
public:
    string minWindow(string s, string t) {
        int count[26*2] = {0};
        bool exist[26*2] = {0};
        for(char c : t){
            count[CODE(c)]++;
            exist[CODE(c)] = true;
        }

        int s_count[26*2] = {0};
        for(char c : s){
            s_count[CODE(c)]++;
        }

        for(int i = 0; i < 2*26; ++i){
            if(s_count[i] < count[i]) return "";
        }

        int front = -1, back, remain = t.size();
        int min_val, min_front, min_back;
        char front_char;
        for(int i = 0; i < s.size(); ++i){
            if(!exist[CODE(s[i])]) continue;

            if(front == -1){
                front = i;
                front_char = s[i];
            }

            if(remain > 0 && count[CODE(s[i])] > 0){
                remain--;
                if(remain == 0){
                    back = i;
                    min_val = back-front+1;
                    min_front = front;
                    min_back = back;
                }
            }
            count[CODE(s[i])]--;

            if(front != -1 && front != i){
                // too many
                if(s[i] == front_char && count[CODE(s[i])] < 0){ 
                    // move front
                    while(true){
                        if(exist[CODE(s[front])]){
                            if(count[CODE(s[front])] < 0){
                                count[CODE(s[front])]++;
                            }else{
                                front_char = s[front];
                                break;
                            }
                        }
                        front++;
                    }
                    back = i;
                    if(back-front+1 < min_val){
                        min_front = front;
                        min_back = back;
                        min_val = back-front+1;
                    }
                }
            }
        }

        return string(s.begin()+min_front, s.begin()+min_back+1);
    }
};
// @lc code=end


int main(){
    Solution s;
    cerr << s.minWindow("ab", "b");
    return 0;
}
