/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 */

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h_angle = (hour%12)*30 + minutes*0.5;
        double m_angle = minutes*6;

        double diff = max(h_angle, m_angle) - min(h_angle, m_angle);
        return min(diff, 360-diff);
    }
};
// @lc code=end

