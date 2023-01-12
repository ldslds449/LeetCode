/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:

    void heapify(vector<int>& vec, int idx, int size){
        if(idx*2+1 >= size) return;
        if(idx*2+2 >= size || vec[idx*2+1] > vec[idx*2+2]){
            if(vec[idx*2+1] > vec[idx]){
                swap(vec[idx], vec[idx*2+1]);
                heapify(vec, idx*2+1, size);
            }
        }else{
            if(vec[idx*2+2] > vec[idx]){
                swap(vec[idx], vec[idx*2+2]);
                heapify(vec, idx*2+2, size);
            }
        }
    }

    void heap(vector<int>& vec, int size){
        int idx = vec.size() / 2 - 1;
        for(int i = idx; i >= 0; --i){
            heapify(vec, i, size);
        }
    }

    int minStoneSum(vector<int>& piles, int k) {
        int size = piles.size();
        heap(piles, size);
        for(int i = 0; i < k; ++i){
            piles[0] -= piles[0] / 2;
            heapify(piles, 0, size);
        }
        int total = 0;
        for(int i = 0; i < size; ++i){
            total += piles[i];
        }
        return total;
    }
};
// @lc code=end

