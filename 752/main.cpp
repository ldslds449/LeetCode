/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool find(vector<string>& deadends, string target){
        int start = 0, end = deadends.size();
        while(start < end){
            int mid = (end-start)/2 + start;
            if(deadends[mid] == target){
                return true;
            }else if(deadends[mid] < target){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return false;
    }

    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        
        sort(deadends.begin(), deadends.end());

        unordered_set<string> visit;

        int count = 0;
        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                string now = q.front(); q.pop();
                if(now == target) return count;
                if(find(deadends, now)) continue;
                if(visit.count(now)) continue;
                visit.insert(now);
                for(int i = 0; i < 4; ++i){
                    string new_now = now;
                    int offset = now[i] - '0';
                    new_now[i] = ((offset+1) % 10) + '0';
                    q.push(new_now);
                    new_now[i] = ((offset+9) % 10) + '0';
                    q.push(new_now);
                }
            }
            count++;
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> strs{"0201","0101","0102","1212","2002"};
    s.openLock(strs, "0202");
}
