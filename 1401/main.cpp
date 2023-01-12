/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 */

// @lc code=start
class Solution {
public:
    int dist(int x1, int y1, int x2, int y2){
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(x1 <= xCenter && xCenter <= x2) return (y1-radius <= yCenter) && (yCenter <= y2+radius);
        if(y1 <= yCenter && yCenter <= y2) return (x1-radius <= xCenter) && (xCenter <= x2+radius);
        if(xCenter < x1 && yCenter > y2) return dist(xCenter, yCenter, x1, y2) <= radius*radius;
        if(xCenter < x1 && yCenter < y1) return dist(xCenter, yCenter, x1, y1) <= radius*radius;
        if(xCenter > x2 && yCenter < y1) return dist(xCenter, yCenter, x2, y1) <= radius*radius;
        if(xCenter > x2 && yCenter > y2) return dist(xCenter, yCenter, x2, y2) <= radius*radius;
        return false;
    }
};
// @lc code=end

