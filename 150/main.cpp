/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<long long int> s;
        for(string &token : tokens){
            if((token[0] <= '9' && token[0] >= '0') || (token[0] == '-' && token.size() > 1)){
                s.push(stoi(token));
            }else{
                long long int op2 = s.top(); s.pop();
                long long int op1 = s.top(); s.pop();
                if(token == "+"){
                    s.push(op1 + op2);
                }else if(token == "-"){
                    s.push(op1 - op2);
                }else if(token == "*"){
                    s.push(op1 * op2);
                }else{
                    s.push(op1 / op2);
                }
            }
        }
        return s.top();
    }
};
// @lc code=end

