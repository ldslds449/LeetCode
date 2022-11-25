/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */ int guess(int num);


class Solution {
public:
    int guessNumber(int n) {
        // binary search
        unsigned int left = 1, right = n;
        while(left <= right){
            unsigned int mid = (right-left+1)/2 + left;
            int r = guess(mid);
            if(r == 0) return mid;
            if(r == 1){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
};
// @lc code=end

