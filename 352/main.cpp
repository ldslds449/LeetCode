/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

#include <vector>
#include <set>
#include <climits>

using namespace std;

// @lc code=start
class SummaryRanges {
public:
    set<vector<int>> intervals;

    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it = intervals.upper_bound({value, INT_MAX});
        int start = value, end = value;
        if(it != intervals.end() && (*it)[0] == value+1){
            end = (*it)[1];
        }
        if(it != intervals.begin()){
            if((*prev(it))[1] >= value) return;
            if((*prev(it))[1] == value-1) start = (*prev(it))[0];
        }

        if(start != value && end != value) intervals.erase(prev(it), next(it));
        else if(start != value) intervals.erase(prev(it), it);
        else if(end != value) intervals.erase(it, next(it));

        intervals.insert({start, end});
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(intervals.begin(), intervals.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

