/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int lineOverlap(int a1, int a2, int b1, int b2){
        int diff = min(a2,b2)-max(a1,b1);
        return diff >= 0 ? diff : 0;
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int width = lineOverlap(ax1, ax2, bx1, bx2);
        int height = lineOverlap(ay1, ay2, by1, by2);
        int overlapArea = width * height;
        int a1 = (bx2-bx1)*(by2-by1);
        int a2 = (ax2-ax1)*(ay2-ay1);
        return a1+a2-overlapArea;
    }
};
// @lc code=end

