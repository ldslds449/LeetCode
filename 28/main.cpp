/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size(), 0);
        for(int a = 1, b = 0; a < needle.size(); ++a){
            if(needle[a] == needle[b]){
                next[a] = ++b;
            }else if(b != 0){
                b = next[b-1];
                --a;
            }else{
                b = 0;
                next[a] = b;
            }
        }

        for(int a = 0, b = 0; a < haystack.size(); ++a){
            if(needle[b] == haystack[a]){
                b++;
                if(b == needle.size()){
                    return a - needle.size() + 1;
                }
            }else if(b != 0){
                b = next[b-1];
                a--;
            }
        }

        return -1;
    }
};
// @lc code=end

