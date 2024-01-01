#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(int n, int index, int maxSum, long long val){
        val--;
        long long left = (index > val ? (val)*(val+1)/2 : (val-index+val)*(index+1)/2);
        long long right = (n-index-1 > val ? (val)*(val+1)/2 : (val-(n-index-1)+val)*(n-index)/2);
    
        long long total = left + right - val;
        return total <= maxSum - n;    
    }
  
    int maxValue(int n, int index, int maxSum) {
        int left = 0, right = 1e9+1;
        while(left < right){
            int mid = (right - left)/2 + left;
            if(check(n, index, maxSum, mid)){
                left = mid+1;  
            }else{
                right = mid;
            }
        }
    
        return left-1;
    }
};