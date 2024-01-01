/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

// @lc code=start
struct hash_pair{
    std::size_t operator()(const pair<string,string> &a) const {
        hash<string> str_hash;
        return str_hash(a.first) ^ str_hash(a.second);
    }
};

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> id_table;
    unordered_map<pair<string,string>, pair<int,int>, hash_pair> t_table;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        id_table[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &in = id_table[id];
        auto &e = t_table[{in.first, stationName}];
        e.first += t - in.second;
        e.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &e = t_table[{startStation, endStation}];
        return static_cast<double>(e.first) / e.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

