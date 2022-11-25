/*
 * @lc app=leetcode id=1654 lang=cpp
 *
 * [1654] Minimum Jumps to Reach Home
 */

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
struct Data{
    int x;
    bool backward;
    Data(int x, bool backward): x(x), backward(backward) {}
};

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> visited;
        for(int f : forbidden){
            visited.insert(f);
            visited.insert(-f);
        }

        queue<Data> q;
        q.push(Data(0, false));

        int dist = 0;
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                auto now = q.front(); q.pop();
                if(now.x < 0) continue;
                if(now.x == x) return dist;
                if(!now.backward){
                    if(visited.count(now.x)) continue;
                    if(visited.count(-now.x)){
                        q.push(Data(now.x - b, true));
                    }else{
                        q.push(Data(now.x + a, false));
                        q.push(Data(now.x - b, true));
                    }
                    visited.insert(now.x);
                    visited.insert(-now.x);
                }else{
                    if(visited.count(now.x)) continue;
                    if(visited.count(-now.x)) continue;
                    visited.insert(-now.x);
                    q.push(Data(now.x + a, false));
                }
            }
            dist++;
        }
        return -1;
    }
};
// @lc code=end

