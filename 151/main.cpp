/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string tmp = "";
        stack<string> st;
        for(char c : s){
            if(c == ' '){
                if(tmp.size() != 0){
                    st.push(tmp);
                    tmp = "";
                }
            }else{
                tmp += c;
            }
        }
        if(tmp.size() > 0) st.push(tmp);
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
            if(st.size()) s+= " ";
        }
        return s;
    }
};
// @lc code=end

