/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visit, legal(wordList.begin(), wordList.end());
        visit.insert(beginWord);

        int diff = 1;
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                string now = q.front(); q.pop();
                if(now == endWord) return diff;

                for(int k = 0; k < beginWord.size(); ++k){
                    string new_str = now;
                    for(int h = 0; h < 25; ++h){
                        new_str[k] = (new_str[k] - 'a' + 1) % 26 + 'a';
                        if(legal.count(new_str) && visit.count(new_str) == 0){
                            visit.insert(new_str);
                            q.push(new_str);
                        }
                    }
                }
            }
            diff++;
        }
        return 0;
    }
};
// @lc code=end

