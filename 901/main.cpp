/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

#include <vector>

using namespace std;

// @lc code=start
class StockSpanner {
public:
    vector<int> list;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        for(int i = list.size()-1; i >= 0; i--){
            if(list[i] <= price) count++;
            else break;
        }
        list.push_back(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

