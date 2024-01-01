/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class KthLargest {
public:
    int K;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;

    void insert(int &n){
        pq.push(n);
        if(pq.size() > K) pq.pop();
    }

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto &n : nums){
            insert(n);
        }
    }
    
    int add(int val) {
        insert(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

