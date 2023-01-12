/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:

    void sink(vector<int> &vec, int idx, int size, vector<vector<int>>& tasks, int axis){
        while(idx*2+1 < size){
            int target = idx*2+1;
            if(idx*2+2 < size && (tasks[vec[idx*2+2]][axis] < tasks[vec[idx*2+1]][axis] || 
                (tasks[vec[idx*2+2]][axis] == tasks[vec[idx*2+1]][axis] && vec[idx*2+2] < vec[idx*2+1])
                )){
                target++;
            }

            if(tasks[vec[target]][axis] < tasks[vec[idx]][axis] || (
                tasks[vec[target]][axis] == tasks[vec[idx]][axis] && vec[target] < vec[idx]
            )){
                swap(vec[target], vec[idx]);
                idx = target;
                continue;
            }
            break;
        }
    }

    void swim(vector<int> &vec, int idx, vector<vector<int>>& tasks, int axis){
        while(idx >= 0 && (
            tasks[vec[(idx-1)/2]][axis] > tasks[vec[idx]][axis] ||
            (tasks[vec[(idx-1)/2]][axis] == tasks[vec[idx]][axis] && vec[(idx-1)/2] > vec[idx])
        )){
            swap(vec[(idx-1)/2], vec[idx]);
            idx = (idx-1)/2;
        }
    }

    void heap(vector<int> &vec, int size, vector<vector<int>>& tasks, int axis){
        int end = size/2 - 1;
        for(int i = end; i >= 0; --i){
            sink(vec, i, size, tasks, axis);
        }
    }

    int delete_min(vector<int> &vec, int &size, vector<vector<int>>& tasks, int axis){
        swap(vec[0], vec[size-1]);
        sink(vec, 0, size-1, tasks, axis);
        size--;
        return vec[size];
    }

    void insert(vector<int> &vec, int target, int &size, vector<vector<int>>& tasks, int axis){
        vec[size] = target;
        swim(vec, size, tasks, axis);
        size++;
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> avail(tasks.size()), need(tasks.size());
        iota(avail.begin(), avail.end(), 0);
        heap(avail, tasks.size(), tasks, 0);

        int avail_count = tasks.size(), need_count = 0;
        long long time = 0;
        vector<int> order;
        for(int i = 0; i < tasks.size(); ++i){
            if(need_count == 0 && avail_count > 0 && tasks[avail[0]][0] > time) time = tasks[avail[0]][0];
            while(avail_count > 0 && tasks[avail[0]][0] <= time){
                int t = delete_min(avail, avail_count, tasks, 0);
                insert(need, t, need_count, tasks, 1);
            }

            int t = delete_min(need, need_count, tasks, 1);
            
            time += tasks[t][1];
            order.push_back(t);
        }

        return order;
    }
};
// @lc code=end

int main(){
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
    Solution s;
    s.getOrder(tasks);
}
