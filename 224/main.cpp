/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

#include <string>
#include <cctype>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int digit(string &s, int &i){
        int num = 0;
        for(; i < s.size() && isdigit(s[i]); ++i){
            num *= 10;
            num += s[i] - '0';
        }
        i--;
        return num;
    }

    int calculate(string s) {
        int count = 0; bool negative = false;
        stack<pair<int,bool>> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            else if(isdigit(s[i])){
                count += (negative ? -digit(s, i) : digit(s, i));
            }else if(s[i] == '-'){
                negative = true;
            }else if(s[i] == '+'){
                negative = false;
            }else if(s[i] == '('){
                st.push({count, negative});
                count = 0, negative = false;
            }else if(s[i] == ')'){
                count = st.top().first + (st.top().second ? -count : count);
                negative = false;
                st.pop();
            }
        }
        return count;
    }
};
// @lc code=end

