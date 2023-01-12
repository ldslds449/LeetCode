/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start
class MyCalendar {
public:
    unordered_map<long long, bool> tree, lazy;

    MyCalendar() {
        
    }

    bool lookup(long long idx, int left, int right, int start, int end){
        // cerr << "[" << left << "," << right << "] " << tree[idx] << "\n";
        if(start >= right || end <= left) return false;
        else if(start <= left && right <= end) return tree[idx];
        int mid = (right - left)/2 + left;
        return lazy[idx] | lookup(idx*2+1, left, mid, start, end) | lookup(idx*2+2, mid, right, start, end);
    }

    void update(long long idx, int left, int right, int start, int end){
        // cerr << "! [" << left << "," << right << "] " << "\n";
        if(start >= right || end <= left) return;
        else if(start <= left && right <= end){
            tree[idx] = true;
            lazy[idx] = true;
            return;
        }
        int mid = (right - left)/2 + left;
        update(idx*2+1, left, mid, start, end);
        update(idx*2+2, mid, right, start, end);
        tree[idx] = true;
    }
    
    bool book(int start, int end) {
        if(lookup(0, 0, 1e9+1, start, end)) return false;
        update(0, 0, 1e9+1, start, end);
        return true;
    }
};

int main(){
    MyCalendar calendar;
    cerr << calendar.book(23, 32) << "\n";
    cerr << calendar.book(21, 30) << "\n";
    cerr << calendar.book(26, 31) << "\n";
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

