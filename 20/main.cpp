/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else{
                if(c == ')' && (st.empty() || st.top() != '(')) return false;
                if(c == ']' && (st.empty() || st.top() != '[')) return false;
                if(c == '}' && (st.empty() || st.top() != '{')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

