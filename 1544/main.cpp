/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c : s){
            if(st.empty() || abs(st.top()-c) != abs('A'-'a')){
                st.push(c);
            }else{
                st.pop();
            }
        }
        string r = "";
        while(!st.empty()){
            r += st.top();
            st.pop();
        }
        return string(r.rbegin(), r.rend());
    }
};
// @lc code=end

