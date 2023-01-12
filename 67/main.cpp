/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);

        int a_idx = a.size()-1, b_idx = b.size()-1;
        int carry = 0;

        while(a_idx >= 0){
            int sum = a[a_idx] - '0' + carry + (b_idx >= 0 ? + b[b_idx] - '0' : 0);
            carry = sum >> 1;
            a[a_idx] = (sum & 1) + '0';
            a_idx--; b_idx--;
        }

        return (carry > 0 ? "1" : "") + a;
    }
};
// @lc code=end

