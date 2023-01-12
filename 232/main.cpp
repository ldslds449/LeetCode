/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <stack>

using namespace std;

// @lc code=start
class MyQueue {
public:
    stack<int> back, front;

    MyQueue() {
        
    }
    
    void push(int x) {
        back.push(x);
    }
    
    int pop() {
        if(front.empty()){
            // move
            while(!back.empty()){
                front.push(back.top());
                back.pop();
            }
        }
        int tmp = front.top();
        front.pop();
        return tmp;
    }
    
    int peek() {
        if(front.empty()){
            // move
            while(!back.empty()){
                front.push(back.top());
                back.pop();
            }
        }
        return front.top();
    }
    
    bool empty() {
        return back.empty() && front.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

