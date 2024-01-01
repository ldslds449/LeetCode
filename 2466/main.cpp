#include <vector>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 1);
        const int mod = 1e9+7;
        for(int i = 1; i <= high; ++i){
            int pre0 = i-zero >= 0 ? dp[i-zero] : 0;
            int pre1 = i-one >= 0 ? dp[i-one] : 0;
            dp[i] = (pre0 + pre1) % mod;
        }

        int total = 0;
        for(int i = low; i <= high; ++i){
          total += dp[i];
          total %= mod;
        }

        return total;
    }
};