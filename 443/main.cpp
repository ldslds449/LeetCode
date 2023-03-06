/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

    int compress(vector<char>& chars) {
        int len = 0;
        int len_char = 1;
        for(int i = 1; i <= chars.size(); ++i){
            if(i == chars.size() || chars[i] != chars[i-1]){
                if(len_char == 1){
                    chars[len] = chars[i-1];
                    len++;
                }else{
                    chars[len++] = chars[i-1];
                    int start = len, end;
                    do{
                        chars[len++] = '0' + (len_char%10);
                        len_char /= 10;
                    }while(len_char > 0);
                    end = len-1;
                    while(start < end){
                        swap(chars[start++], chars[end--]);
                    }
                }
                len_char = 0;
            }
            len_char++;
        }
        return len;
    }
};
// @lc code=end

