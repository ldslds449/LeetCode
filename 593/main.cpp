/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    inline bool is90Degree(vector<int> &v1, vector<int> &v2){
        return (v1[0]*v2[0] + v1[1]*v2[1]) == 0;
    }

    inline vector<int> vec(vector<int>& p1, vector<int>& p2){
        return vector<int>{p2[0]-p1[0], p2[1]-p1[1]};
    }

    inline int dist(vector<int>& p1, vector<int>& p2){
        int x_diff = p2[0]-p1[0];
        int y_diff = p2[1]-p1[1];
        return x_diff*x_diff + y_diff*y_diff;
    }

    struct Edge{
        int dist;
        vector<int> vec;
    };

    bool validCorner(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4) {
        vector<vector<int>> points = {p2, p3, p4};
        
        vector<Edge> edges;
        for(int i = 0; i < 3; ++i){
            edges.push_back(Edge());
            edges[i].dist = dist(p1, points[i]);
            edges[i].vec = vec(p1, points[i]);
        }
        
        sort(edges.begin(), edges.end(), 
            [&](Edge e1, Edge e2)->bool{
                return e1.dist < e2.dist;
            }
        );

        if(edges[0].dist != edges[1].dist) return false;
        if(edges[0].dist == 0) return false;
        if(!is90Degree(edges[0].vec, edges[1].vec)){
            return false;
        }
        return true;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        return validCorner(p1,p2,p3,p4) &&
            validCorner(p2,p1,p3,p4) &&
            validCorner(p3,p2,p1,p4) &&
            validCorner(p4,p2,p3,p1);

    }
};
// @lc code=end

