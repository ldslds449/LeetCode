/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

#include <vector>
#include <cstring>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    int count[61][61];

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        memset(count, 0, sizeof(count));

        vector<pair<int,int>> ones_1;
        for(int i = 0; i < img1.size(); ++i){
            for(int j = 0; j < img1.front().size(); ++j){
                if(img1[i][j] == 1){
                    ones_1.push_back({i, j});
                }
            }
        }
        vector<pair<int,int>> ones_2;
        for(int i = 0; i < img2.size(); ++i){
            for(int j = 0; j < img2.front().size(); ++j){
                if(img2[i][j] == 1){
                    ones_2.push_back({i, j});
                }
            }
        }

        for(int i = 0; i < ones_1.size(); ++i){
            for(int j = 0; j < ones_2.size(); ++j){
                int dx = ones_1[i].first - ones_2[j].first;
                int dy = ones_1[i].second - ones_2[j].second;
                count[dx+30][dy+30]++;
            }
        }
        
        int max_val = 0;
        for(int i = 0; i < 61; ++i){
            for(int j = 0; j < 61; ++j){
                max_val = max(count[i][j], max_val);
            }
        }
        return max_val;
    }
};
// @lc code=end

