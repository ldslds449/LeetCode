/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

#include <unordered_map>

using namespace std;

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {}

    unordered_map<int,int> event_cnt, lazy;

    int query(int l, int r, int idx, int start, int end){
        if(end <= l || start >= r) return 0;
        if(start <= l && end >= r){
            return event_cnt[idx];
        }
        int mid = (r-l)/2 + l;
        int r1 = query(l, mid, (idx<<1), start, end);
        int r2 = query(mid, r, (idx<<1)|1, start, end);
        return lazy[idx] + max(r1, r2);
    }

    void update(int l, int r, int idx, int start, int end){
        if(end <= l || start >= r) return;
        if(start <= l && end >= r){
            lazy[idx]++;
            event_cnt[idx]++;
            return;
        }
        int mid = (r-l)/2 + l;
        update(l, mid, (idx<<1), start, end);
        update(mid, r, (idx<<1)|1, start, end);
        event_cnt[idx] = lazy[idx] + max(event_cnt[idx<<1], event_cnt[(idx<<1)|1]);
    }
    
    bool book(int start, int end) {
        int count = query(0, 1e9+1, 1, start, end);
        if(count >= 2) return false;
        update(0, 1e9+1, 1, start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

