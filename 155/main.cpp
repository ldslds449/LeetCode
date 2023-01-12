/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <vector>

using namespace std;

// @lc code=start
class MinStack {
public:
    vector<int> s, m;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
        if(m.size() == 0 || m.back() >= val){
            m.push_back(val);
        }
    }
    
    void pop() {
        if(m.back() == s.back()) m.pop_back();
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return m.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

