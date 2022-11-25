/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class MedianFinder {
public:
    MedianFinder() {}

    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>> max_pq;
    
    void addNum(int num) {
        if(max_pq.empty()){
            max_pq.push(num); 
        }else{
            if(num > max_pq.top()){
                min_pq.push(num);
            }else{
                max_pq.push(num);
            }
        }
        while(max_pq.size() > (max_pq.size()+min_pq.size()+1)/2){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        while(min_pq.size() > (max_pq.size()+min_pq.size())/2){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    double findMedian() {
        if((max_pq.size() + min_pq.size()) % 2 == 0){
            return (double)(max_pq.top() + min_pq.top()) / 2;
        }else{
            return max_pq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main(){
    MedianFinder solution;
    solution.addNum(1);
    solution.addNum(2);
}
