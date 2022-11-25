/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s){
            if(st.empty() || st.top() != c){
                st.push(c);
            }else{
                st.pop();
            }
        }
        string r = "";
        while(!st.empty()){
          r += st.top(); st.pop();
        }
        return string(r.rbegin(), r.rend());
    }
};
// @lc code=end

