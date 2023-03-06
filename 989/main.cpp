/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int idx = num.size()-1;
        while(k > 0){
            num[idx] += (k%10);
            k /= 10;
            if(num[idx] >= 10){
                k++;
                num[idx] -= 10;
            }
            if(idx == 0 && k > 0){
                num.insert(num.begin(), 0);
            }else{
                idx--;
            }
        }
        return num;
    }
};
// @lc code=end

